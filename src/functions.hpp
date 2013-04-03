

#ifndef __libtorrent_js__functions__
#define __libtorrent_js__functions__

#include <iostream>
#include <v8.h>

#include <libtorrent/bencode.hpp>
#include <libtorrent/lazy_entry.hpp>
#include <libtorrent/session.hpp>

using namespace v8;

namespace libtorrentjs {

    Handle<Object> createObject(libtorrent::lazy_entry const &e);
    
    Handle<Value> bdecode(const Arguments& args);
    
    Handle<Value> create_session(const Arguments& args);
    
    libtorrent::dht_settings js_to_dht_settings(const Local<Value> &obj);
    
};

#endif /* defined(__libtorrent_js__functions__) */
