//
//  event_dispatcher.cpp
//  libtorrent-js
//
//  Created by Patricio Villalobos on 3/25/13.
//
//

#include "event_dispatcher.hpp"

namespace libtorrentjs {
    
    Local<Object> transform_tracker_alert(libtorrent::tracker_alert const &alert) {
    
         // TODO: implement torrent alert after implement torrent_handle wrapper
        
        Local<Object> obj = Object::New();
        
        obj->Set(String::New("url"), String::New(alert.url.c_str()));
        
        return obj;
        
    }

    
    Local<Value> transform_dht_reply(libtorrent::dht_reply_alert const &alert) {
        
        Local<Object> obj = transform_tracker_alert(alert);
        
        obj->Set(String::New("num_peers"), Number::New(alert.num_peers));
        
        return obj;
        
    }
    
    Local<Value> transform_dht_get_peers(libtorrent::dht_get_peers_alert const &alert) {
        
        Local<Object> obj = Object::New();
        
        obj->Set(String::New("info_hash"), String::New(libtorrent::to_hex(alert.info_hash.to_string()).c_str()));
        
        return obj;
        
    }
    
    
    Local<Value> transform_dht_announce(libtorrent::dht_announce_alert const &alert) {
        
        
        Local<Object> obj = Object::New();
        
        obj->Set(String::New("ip"), String::New(alert.ip.to_string().c_str()));
        obj->Set(String::New("port"), Number::New(alert.port));
        obj->Set(String::New("info_hash"), String::New(libtorrent::to_hex(alert.info_hash.to_string()).c_str()));
        
        return obj;
        
    }
    
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
    
};