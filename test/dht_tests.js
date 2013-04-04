var addon = require('../build/Release/torrentjs');


var ses = addon.create_session();


function on_dht_bootstrap() {

    console.log('(dht_bootstrap_alert) Starting DHT');
}

function on_dht_announce(alert) {

    console.log("(dht_announce_alert) IP: " + alert.ip + ":" + alert.port + " INFO_HASH: " +alert.info_hash);

}

function on_dht_reply(alert) {

    console.log("(dht_reply_alert) NUM_PEERS: " + alert.num_peers);

}

function on_dht_get_peers(alert) {

    console.log("(dht_get_peers_alert) INFO_HASH: "+ alert.info_hash)

}

ses.on("dht_bootstrap_alert", on_dht_bootstrap);
ses.on("dht_announce_alert", on_dht_announce);
ses.on("dht_reply_alert", on_dht_reply);
ses.on("dht_get_peers_alert", on_dht_get_peers);

ses.set_dht_settings({max_torrents: 1000});

ses.start_dht();

ses.add_dht_router("router.bittorrent.com", 6881);

console.log(ses.is_dht_running());

ses.listen_on(6881, 6889);


setTimeout(tof, 1000);


function tof() {

    ses.get_alerts();

    setTimeout(tof, 1000);

}