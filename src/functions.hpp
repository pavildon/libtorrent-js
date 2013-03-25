

#ifndef __libtorrent_js__functions__
#define __libtorrent_js__functions__

#include <iostream>
#include <v8.h>

#include <libtorrent/bencode.hpp>
#include <libtorrent/lazy_entry.hpp>

using namespace v8;

Handle<Object> createObject(libtorrent::lazy_entry const &e);

Handle<Value> bdecode(const Arguments& args);

Handle<Value> create_session(const Arguments& args);

#endif /* defined(__libtorrent_js__functions__) */
