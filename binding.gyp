{
  "targets": [
    {
      "target_name": "torrentjs",
      "sources": [ "src/torrentjs.cpp" ],
      "defines": [ "BOOST_ASIO_SEPARATE_COMPILATION" ],
      "link_settings" : {
          "libraries": [
	      "-lboost_system",
              "/usr/local/lib/libtorrent.a"
	  ]
      }
    }
  ]
}
