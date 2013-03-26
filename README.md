libtorrent-js
=============

Relaxed Bindings to some functionalities of Rasterbar LibTorrent ( )  for NodeJS


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
ses.add_torrent('linuxmint-14.1-mate-dvd-32bit.iso.torrent');
ses.on('state_update_alert', on_state_change);

function on_state_change(status) {
        console.log('---- status ----');
        status.forEach( function(item) {
                console.log( item.name + ' : DL ' + (item.download_rate/1024) + ' kb/s |' + ' UL ' + (item.upload_rate/1024) + 'kb/s');

        });
}


function timeoutfunc() {
        ses.post_torrent_updates();
        ses.test++;
        ses.get_alerts();
        setTimeout(timeoutfunc, 1000);
}

timeoutfunc();

```

TODO
====

as you can see theres A LOT to do
