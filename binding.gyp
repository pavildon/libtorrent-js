{
  "targets": [
    {
      "target_name": "torrentjs",
      "sources": [ 
        "src/session.cpp",
        "src/functions.cpp",
        "src/torrentjs.cpp",
        "src/event_dispatcher.cpp"
        ],
      "include_dirs": ['src/'],
      "defines": [ "BOOST_ASIO_SEPARATE_COMPILATION" ],
      'cflags_cc!': [ '-fno-rtti' ],
      "link_settings" : {
          "libraries": [
	      "/usr/local/lib/libboost_system.a",
              "/usr/local/lib/libtorrent.a"
	  ]},
      'conditions': [
          ['OS=="mac"', {
             'xcode_settings': {
             'GCC_ENABLE_CPP_RTTI': 'YES'
          }
         }]
       ]

    }
  ]
}
