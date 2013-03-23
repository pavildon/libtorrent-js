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

var addon = require('torrentjs');

console.log(addon.bdecode('d3:cow3:moo4:spam4:eggse'));


TODO
====

as you can see theres A LOT to do
