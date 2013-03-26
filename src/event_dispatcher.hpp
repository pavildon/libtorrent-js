//
//  event_dispatcher.h
//  libtorrent-js
//
//  Created by Patricio Villalobos on 3/25/13.
//
//

#ifndef __libtorrent_js__event_dispatcher__
#define __libtorrent_js__event_dispatcher__

#include <iostream>

#include <v8.h>

#define TORRENT_MAX_ALERT_TYPES 64

#include <libtorrent/alert.hpp>
#include <libtorrent/alert_types.hpp>

using namespace v8;



namespace libtorrentjs {
    
    Local<Value> transform_changed_status( std::vector<libtorrent::torrent_status> const &status);
    
    // this huge piece of garbage was generated with ake_alert_functions.js located in util/
    
    struct event_dispatcher {
        
        Persistent<Object> callback_object;
        
        void operator()(libtorrent::torrent_added_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("torrent_added_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::add_torrent_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("add_torrent_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::torrent_removed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("torrent_removed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::read_piece_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("read_piece_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::external_ip_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("external_ip_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::listen_failed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("listen_failed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::listen_succeeded_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("listen_succeeded_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::portmap_error_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("portmap_error_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::portmap_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("portmap_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::portmap_log_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("portmap_log_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::file_error_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("file_error_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::torrent_error_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("torrent_error_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::file_renamed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("file_renamed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::file_rename_failed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("file_rename_failed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::tracker_announce_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("tracker_announce_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::tracker_error_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("tracker_error_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::tracker_reply_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("tracker_reply_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::tracker_warning_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("tracker_warning_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::scrape_reply_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("scrape_reply_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::scrape_failed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("scrape_failed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::url_seed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("url_seed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::hash_failed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("hash_failed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::peer_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("peer_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::peer_connect_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("peer_connect_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::peer_ban_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("peer_ban_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::peer_snubbed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("peer_snubbed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::peer_unsnubbed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("peer_unsnubbed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::peer_error_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("peer_error_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::peer_disconnected_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("peer_disconnected_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::invalid_request_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("invalid_request_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::request_dropped_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("request_dropped_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::block_timeout_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("block_timeout_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::block_finished_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("block_finished_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::lsd_peer_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("lsd_peer_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::file_completed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("file_completed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::block_downloading_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("block_downloading_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::unwanted_block_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("unwanted_block_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::torrent_delete_failed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("torrent_delete_failed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::torrent_deleted_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("torrent_deleted_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::torrent_finished_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("torrent_finished_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::performance_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("performance_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::state_changed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("state_changed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::metadata_failed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("metadata_failed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::metadata_received_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("metadata_received_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::fastresume_rejected_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("fastresume_rejected_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::peer_blocked_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("peer_blocked_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::storage_moved_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("storage_moved_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::storage_moved_failed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("storage_moved_failed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::torrent_paused_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("torrent_paused_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::torrent_resumed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("torrent_resumed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::save_resume_data_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("save_resume_data_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::save_resume_data_failed_alert const& a) const
        {
            Local<Value> v = callback_object->Get(String::New("save_resume_data_failed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::stats_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("stats_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::cache_flushed_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("cache_flushed_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::torrent_need_cert_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("torrent_need_cert_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::dht_announce_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("dht_announce_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::dht_get_peers_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("dht_get_peers_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::dht_reply_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("dht_reply_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::dht_bootstrap_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("dht_bootstrap_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::anonymous_mode_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("anonymous_mode_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::rss_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("rss_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::incoming_connection_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("incoming_connection_alert"));
            if(v->IsUndefined()) return;
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!
        }
        
        
        void operator()(libtorrent::state_update_alert const& a) const 
        { 
            Local<Value> v = callback_object->Get(String::New("state_update_alert"));
            if(v->IsUndefined()) return;
            
            Local<Value> argv[1] = { transform_changed_status(a.status) };
            
            Local<Function> cb = Local<Function>::Cast(v);
            cb->Call(Context::GetCurrent()->Global(),1, argv); 
        }
        
    };
}

#endif /* defined(__libtorrent_js__event_dispatcher__) */
