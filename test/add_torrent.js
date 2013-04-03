var addon = require('../build/Release/torrentjs');

var ses = addon.create_session();

ses.add_torrent('ubuntu.torrent');
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


