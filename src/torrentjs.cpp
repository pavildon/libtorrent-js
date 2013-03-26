

#include "torrentjs.hpp"
#include "session.hpp"
#include "functions.hpp"


#include <vector>

#include <node.h>

#include <libtorrent/bencode.hpp>
#include <libtorrent/lazy_entry.hpp>

#include <v8.h>

using namespace v8;
using namespace libtorrentjs;

void init(Handle<Object> exports) {

    Session::Init();
    
    exports->Set(String::NewSymbol("bdecode"),
                 FunctionTemplate::New(bdecode)->GetFunction());
    
    exports->Set(String::NewSymbol("create_session"),
                 FunctionTemplate::New(create_session)->GetFunction());
}

NODE_MODULE(torrentjs, init)