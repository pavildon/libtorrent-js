//
//  session.cpp
//  libtorrent-js
//
//  Created by Patricio Villalobos on 3/23/13.
//
//

#include <node.h>
#include <boost/system/error_code.hpp>

#define TORRENT_MAX_ALERT_TYPES 64

#include <libtorrent/alert.hpp>
#include <libtorrent/alert_types.hpp>

#include "session.hpp"
#include "functions.hpp"

using namespace v8;
using namespace libtorrentjs;

Persistent<Function> Session::constructor;


// the actual object

Session::Session() :
_session()
{
    dispatcher.callback_object = Persistent<Object>::New(Object::New());
}

Session::~Session() {}

void Session::Init()
{
    
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("Session"));
    tpl->InstanceTemplate()->SetInternalFieldCount(5);
    
    // functions
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("add_torrent"),
                                  FunctionTemplate::New(add_torrent)->GetFunction());
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("listen_on"),
                                  FunctionTemplate::New(listen_on)->GetFunction());
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("post_torrent_updates"),
                                  FunctionTemplate::New(post_torrent_updates)->GetFunction());
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("get_alerts"),
                                  FunctionTemplate::New(get_alerts)->GetFunction());
    
    tpl->PrototypeTemplate()->Set(String::NewSymbol("on"),
                                  FunctionTemplate::New(on)->GetFunction());
    
    
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


v8::Handle<v8::Value> Session::load_state(const Arguments& args) {
    HandleScope scope;
    
// TODO: Implement THIS!
    
    return scope.Close(args.This());
    
}


v8::Handle<v8::Value> Session::save_state(const Arguments& args) {
    
    HandleScope scope;
    
// TODO: Implement THIS!
    
    return scope.Close(args.This());
    
}

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

// TODO: maybe this two functions should be called async (with a timer in c++) and not be called implicitly in javascript code
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
        
        using namespace libtorrent;
        
        // please forgive me!
        
        handle_alert<torrent_added_alert,
        add_torrent_alert,
        torrent_removed_alert,
        read_piece_alert,
        external_ip_alert,
        listen_failed_alert,
        listen_succeeded_alert,
        portmap_error_alert,
        portmap_alert,
        portmap_log_alert,
        file_error_alert,
        torrent_error_alert,
        file_renamed_alert,
        file_rename_failed_alert,
        tracker_announce_alert,
        tracker_error_alert,
        tracker_reply_alert,
        tracker_warning_alert,
        scrape_reply_alert,
        scrape_failed_alert,
        url_seed_alert,
        hash_failed_alert,
        peer_alert,
        peer_connect_alert,
        peer_ban_alert,
        peer_snubbed_alert,
        peer_unsnubbed_alert,
        peer_error_alert,
        peer_disconnected_alert,
        invalid_request_alert,
        request_dropped_alert,
        block_timeout_alert,
        block_finished_alert,
        lsd_peer_alert,
        file_completed_alert,
        block_downloading_alert,
        unwanted_block_alert,
        torrent_delete_failed_alert,
        torrent_deleted_alert,
        torrent_finished_alert,
        performance_alert,
        state_changed_alert,
        metadata_failed_alert,
        metadata_received_alert,
        fastresume_rejected_alert,
        peer_blocked_alert,
        storage_moved_alert,
        storage_moved_failed_alert,
        torrent_paused_alert,
        torrent_resumed_alert,
        save_resume_data_alert,
        save_resume_data_failed_alert,
        stats_alert,
        cache_flushed_alert,
        torrent_need_cert_alert,
        dht_announce_alert,
        dht_get_peers_alert,
        dht_reply_alert,
        dht_bootstrap_alert,
        anonymous_mode_alert,
        rss_alert,
        incoming_connection_alert,
        state_update_alert
        >::handle_alert( a, s->dispatcher);
        
        
        a = s->_session.pop_alert();
        
    }
    
    
    return  scope.Close(args.This());
}

v8::Handle<v8::Value> Session::on(const Arguments& args) {
    
    HandleScope scope;
    
    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());
    
    if(args[0]->IsString() && args[1]->IsFunction()) {
        s->dispatcher.callback_object->Set(args[0]->ToString(), args[1]);
    }
    
    return scope.Close(args.This());
}



// DHT Functions

v8::Handle<v8::Value> Session::start_dht(const Arguments& args) {
    
    HandleScope scope;
    
    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());
    
    s->_session.start_dht();
    
    return scope.Close(args.This());
}

v8::Handle<v8::Value> Session::stop_dht(const v8::Arguments &args) {
    
    HandleScope scope;
    
    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());
    
    s->_session.stop_dht();
    
    return scope.Close(args.This());
}

v8::Handle<v8::Value> Session::set_dht_settings(const v8::Arguments &args) {
    
    HandleScope scope;
    
    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());
    
    libtorrent::dht_settings dht_settings = js_to_dht_settings(args[0]);
    
    s->_session.set_dht_settings(dht_settings);
    
    return scope.Close(args.This());
}

v8::Handle<v8::Value> Session::is_dht_running(const Arguments& args) {
    
    HandleScope scope;
    
    Session *s = node::ObjectWrap::Unwrap<Session>(args.This());

    bool is = s->_session.is_dht_running();
    
    Handle<Boolean> ret(Boolean::New(is));
    
    return scope.Close(ret);
}









