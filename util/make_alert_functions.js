var fs = require('fs');
var readline = require('readline');
var util = require('util');

var rl = readline.createInterface({

    input: fs.createReadStream('alerts'),
    output: process.stdout,
    terminal: false

});

var functionTemplate =  '' +
    'void operator()(libtorrent::%s const& a) const \n' +
    '{ \n' +
    '    Local<Value> v = callback_object->Get(String::New("%s"));\n' +
    '    if(v->IsUndefined()) return;\n' +
    '    Local<Function> cb = Local<Function>::Cast(v);\n' +
    '    cb->Call(Context::GetCurrent()->Global(),0, NULL); // modify this!\n' +
    '}\n\n';

rl.on('line', function (line) {
    var line2 = util.format(functionTemplate, line, line);
    console.log(line2);
});



