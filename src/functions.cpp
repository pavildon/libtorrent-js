//
//  functions.cpp
//  libtorrent-js
//
//  Created by Patricio Villalobos on 3/23/13.
//
//



#include "functions.hpp"
#include "session.hpp"

using namespace libtorrentjs;

Handle<Object> libtorrentjs::createObject(libtorrent::lazy_entry const &e) {
    
    typedef std::pair<std::string, libtorrent::lazy_entry const *>  pair;
    
    Handle<Object> hashmap;
    int max_len = 0;
    
    
    if(e.type() == libtorrent::lazy_entry::dict_t) {
        hashmap = Object::New();
        max_len = e.dict_size();
    } else if(e.type() == libtorrent::lazy_entry::list_t) {
        hashmap = Array::New();
        max_len = e.list_size();
    }
    
    for(int i = 0; i < max_len; i++) {
        
        libtorrent::lazy_entry const *value;
        
        Handle<Value> v;
        
        if (e.type() == libtorrent::lazy_entry::dict_t) {
            
            value = e.dict_at(i).second;
        } else {
            value = e.list_at(i);
        }
        
        switch (value->type()) {
            case libtorrent::lazy_entry::int_t:
                v = Number::New(value->int_value());
                break;
            case libtorrent::lazy_entry::string_t:
                v = String::New(value->string_ptr(), value->string_length());
                break;
            case libtorrent::lazy_entry::dict_t:
                v = createObject(*value);
                break;
            case libtorrent::lazy_entry::list_t:
                v = createObject(*value);
                break;
            default:
                break;
        }
        
        if (e.type() == libtorrent::lazy_entry::dict_t) {
            hashmap->Set(String::New(e.dict_at(i).first.c_str()), v);
            
        } else if(e.type() == libtorrent::lazy_entry::list_t) {
            hashmap->Set(i, v);
        }
        
    }
    
    return hashmap;
    
}

Handle<Value> libtorrentjs::bdecode(const Arguments& args) {
    
    HandleScope scope;
    
    int len = 0;
    char *v;
    
    String::AsciiValue ascii(args[0]);
    
    if(args[0]->IsStringObject() > 0) {
        len = ascii.length();
        v = *ascii;
        
    } else {
        len = args[0]->ToObject()->GetIndexedPropertiesExternalArrayDataLength();
        v = static_cast<char*>(args[0]->ToObject()->GetIndexedPropertiesExternalArrayData());
    }
    
    std::cout << len << std::endl;
    libtorrent::lazy_entry entry;
    boost::system::error_code e;
    
    int err_pos = 0;
    int ret = libtorrent::lazy_bdecode(&v[0], &v[0] + len, entry, e, &err_pos);
    
    if(ret != 0) {
        std::cout << e.message() << " (" << err_pos << ")"<< std::endl;
        return scope.Close(Null());
    }
    return Null();
    
    Handle<Object> r;
    
    switch (entry.type()) {
        case libtorrent::lazy_entry::dict_t:
            return scope.Close(createObject(entry));
        case libtorrent::lazy_entry::list_t:
            return scope.Close(createObject(entry));
        case libtorrent::lazy_entry::int_t:
            return scope.Close(Number::New(entry.int_value()));
        case libtorrent::lazy_entry::string_t:
            return scope.Close(String::New(entry.string_value().c_str()));
        default:
            return scope.Close(Null());
    }
    
    
}

Handle<Value> libtorrentjs::create_session(const Arguments& args) {
    
    HandleScope scope;
    
    return scope.Close(Session::NewInstance(args));
    
    
}


