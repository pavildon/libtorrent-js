var addon = require('../build/Release/torrentjs');

var fs = require('fs');


function decode(data) {

	function getValue() {
		switch (true) {
			case data[0] == 'd': // dictionary
				return getDictionary();
			break;

			case data[0] == 'l': // list
				return getList();
			break;

			case !isNaN(data[0]): // Strings are stored as <length of string>:<string>:
				return getString();
			break;

			case data[0] == 'i': // Integers are stored as i<integer>e:
				return getInteger();
			break;
		}
	}

	function getDictionary() {
		var dictionary = {};

		data = data.substring(1); // remove 'd'
		while (data[0] != 'e') {
			var key = getString();
			var value = getValue();

			dictionary[key] = value;
		}
		data = data.substring(1); // remove 'e'

		return dictionary;
	}

	function getList() {
		var list = [];

		data = data.substring(1); // remove 'l'
		while (data[0] != 'e') {
			var value = getValue();;
			list.push(value);
		}
		data = data.substring(1); // remove 'e'

		return list;
	}

	function getString() {
		var end = data.indexOf(':');
		var length = data.substr(0, end);
			length = parseInt(length);

		var offset = end + 1;
		var value = data.substr(offset, length);

		data = data.substring(offset + length);

		return value;
	}

	function getInteger() {
		var end = data.indexOf('e');
		var integer = data.substring(1, end);
			integer = parseInt(integer);

		data = data.substring(end + 1); // remove up to 'e'

		return integer;
	}

	return getValue();
}

fs.readFile('ubuntu.torrent', function(err, data) {

	if(err) throw err;

	var str = data.toString('binary');

	var start = (new Date).getTime();
	
	for(var i = 0 ; i < 10000; i++) {
		var obj = addon.bdecode(str)
	}
		
	var diff = (new Date).getTime() - start;

	var start2 = (new Date).getTime();

	for(var i = 0 ; i < 10000; i++) {
		var obj2 = decode(str);
	}

	var diff2 = (new Date).getTime() - start2;
	
	console.log('Uno : ' + diff + "  Dos : " + diff2);

});

console.log(addon.bdecode('d3:cow3:moo4:spam4:eggse'));



