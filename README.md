libtorrent-js
=============

Relaxed Bindings to some functionality of Rasterbar-Liborrent for NodeJS


Building
========

So far it only been tested on MacOS (ml.10.8) but building on linux should be trivial

note that the static version of the libtorrent should be located on /usr/local/lib


1. node-gyp configure
2. node-gyp build


the resulting module should be in ./build/Release/torrent.node


Example
=======


```js
var addon = require('../build/Release/torrentjs');

var ses = addon.create_session();

ses.add_torrent('ubuntu.torrent');

var t = new Object();

t.on_state_change = function (status) {
        status.forEach( function(item) {
                console.log( item.name + ' : DL ' + (item.download_rate/1024) + ' kb/s |' + ' UL ' + (item.upload_rate/1024) + 'kb/s');

        });

};


function timeoutfunc() {
        ses.post_torrent_updates();
        ses.test++;
        ses.get_alerts( t );
        setTimeout(timeoutfunc, 1000);
}

timeoutfunc();

```

TODO
====

as you can see theres A LOT to do
