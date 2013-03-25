{
  "targets": [
    {
      "target_name": "torrentjs",
      "sources": [ 
        "src/session.cpp",
        "src/functions.cpp",
        "src/torrentjs.cpp"
        ],
      "include_dirs": ['src/'],
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
