//
//  session.h
//  libtorrent-js
//
//  Created by Patricio Villalobos on 3/23/13.
//
//

#ifndef __libtorrent_js__session__
#define __libtorrent_js__session__

#include <iostream>

#include <node.h>
#include <v8.h>
#include <libtorrent/session.hpp>

using namespace v8;

Local<Value> transform_changed_status( std::vector<libtorrent::torrent_status> const &status);

class Session : public node::ObjectWrap {
    
    libtorrent::session _session;

    static v8::Handle<v8::Value> New(const Arguments& args);
    static Persistent<Function> constructor;
    
    // functions wraping function in the libtorrent session objects
    
    static v8::Handle<v8::Value> listen_on(const Arguments& args);
    static v8::Handle<v8::Value> add_torrent(const Arguments& args);
    static v8::Handle<v8::Value> post_torrent_updates(const Arguments& args);
    static v8::Handle<v8::Value> get_alerts(const Arguments& args);
    
    
public:

    static void Init();
    static v8::Handle<v8::Value> NewInstance(const Arguments& args);
    
    Session();
    ~Session();
    
};

#endif /* defined(__libtorrent_js__session__) */
