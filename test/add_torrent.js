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


