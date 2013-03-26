//
//  event_dispatcher.cpp
//  libtorrent-js
//
//  Created by Patricio Villalobos on 3/25/13.
//
//

#include "event_dispatcher.hpp"

namespace libtorrentjs {
    
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