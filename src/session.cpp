//
//  session.cpp
//  libtorrent-js
//
//  Created by Patricio Villalobos on 3/23/13.
//
//

#include <node.h>
#include <boost/system/error_code.hpp>

#include <libtorrent/alert_types.hpp>

#include "session.hpp"

using namespace v8;

Persistent<Function> Session::constructor;

// utility functions

Local<Value> transform_changed_status( std::vector<libtorrent::torrent_status> const &status) {
    
    Local<Array> arr = Array::New();
    int count = 0;
    
    for(std::vector<libtorrent::torrent_status>::const_iterator it = status.begin();
        it != status.end(); ++it) {
        
        Handle<Object> obj = Object::New();
        
        obj->Set(String::New("download_rate"), Number::New(it->download_rate));
        obj->Set(String::New("upload_rate"), Number::New(it->upload_rate));
        obj->Set(String::New("num_seeds"), Number::New(it->num_seeds));
        obj->Set(String::New("num_peers"), Number::New(it->num_peers));
        
        // TODO : we really need a wrapper object arround torrent_handle and torrent_status
        
        // this should be changed very soon
        
        obj->Set(String::New("name"), String::New(it->handle.name().c_str()));
        
        
        arr->Set(count++, obj);
    }
    
    return arr;
}


// the actual object

Session::Session() :
    _session()
{}

Session::~Session() {}

void Session::Init()
{

    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("Session"));
    tpl->InstanceTemplate()->SetInternalFieldCount(4);
    
    // functions
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("add_torrent"),
                                  FunctionTemplate::New(add_torrent)->GetFunction());
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("listen_on"),
                                  FunctionTemplate::New(listen_on)->GetFunction());
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("post_torrent_updates"),
                                  FunctionTemplate::New(post_torrent_updates)->GetFunction());
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("get_alerts"),
                                  FunctionTemplate::New(get_alerts)->GetFunction());

    
    constructor = Persistent<Function>::New(tpl->GetFunction());

}

Handle<Value> Session::New(const v8::Arguments &args) {
    
    HandleScope scope;
    
    Session *obj = new Session();
    obj->Wrap(args.This());
    
    return args.This();
    
}

Handle<Value> Session::NewInstance(const v8::Arguments &args) {
    
    HandleScope scope;
    
    Handle<Value> argv[1] = { args[0] };
    
    Local<Object> instance = constructor->NewInstance(1, argv);
    
    return scope.Close(instance);
    
}


// Lib Torrent functions

v8::Handle<v8::Value> Session::listen_on(const Arguments& args) {
    
    HandleScope scope;
    
    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());

    std::pair<int, int> port_pair = std::make_pair(6881, 6889);
    boost::system::error_code ec;

    if (args[0]->IsNumber() && args[1]->IsNumber()) {
        port_pair = std::make_pair(args[0]->NumberValue(), args[1]->NumberValue());
    }
    s->_session.set_alert_mask(libtorrent::alert::error_notification | libtorrent::alert::status_notification );
    
    s->_session.listen_on(port_pair, ec);

    
    return scope.Close(args.This());
    
}


v8::Handle<v8::Value> Session::add_torrent(const Arguments& args) {
    
    HandleScope scope;

    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());

    
 
    if(args[0]->IsString()) {

        String::Utf8Value v(args[0]);
        std::string str(*v);
        boost::system::error_code ec;
        

        libtorrent::add_torrent_params params;
        params.ti = new libtorrent::torrent_info(str, ec);
        
        if(ec) {
            std::cout << ec.message() << std::endl;
        }

        params.save_path = "./";
        
        s->_session.async_add_torrent(params);
        
    }
    
    return scope.Close(args.This());
    
}

// TODO: may be this two functions should be called async (with a timer in c++) and not be called implicitly
v8::Handle<v8::Value> Session::post_torrent_updates(const Arguments& args) {
    HandleScope scope;
    
    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());

    s->_session.post_torrent_updates();
    
    return scope.Close(args.This());
    
}

v8::Handle<v8::Value> Session::get_alerts(const Arguments& args) {
    
    HandleScope scope;

    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());

    std::auto_ptr<libtorrent::alert> a;
    
    a = s->_session.pop_alert();

    while(a.get()) {
        
        switch (a->type()) {
            case libtorrent::state_update_alert::alert_type:
            {
                libtorrent::state_update_alert *su = (libtorrent::state_update_alert *) a.get();
                if(su->status.size()
                   && args[0]->IsObject()
                   && args[0]->ToObject()->Get(String::New("on_state_change"))->IsFunction()) {
                    Local<Function> cb = Local<Function>::Cast(args[0]->ToObject()->Get(String::New("on_state_change")));
                    Local<Value> argv[1] = { transform_changed_status(su->status) };
                    cb->Call(Context::GetCurrent()->Global(), 1, argv);
                }
            }
                break;
            default:
                break;
        }
        
        a = s->_session.pop_alert();
        
    }
    
    
    return  scope.Close(args.This());
}








