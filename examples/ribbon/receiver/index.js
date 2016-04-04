// index.js
'use strict';


//	OSC RECEIVER

const PORT_OSC = 8888;
const OscReceiver = require("osc-receiver");

let receiver = new OscReceiver();
receiver.bind(PORT_OSC);


//	OSC MESSAGES HANDLING

receiver.on('/positions', function(x, y, z, index) {
	// console.log('on Positions : ', arguments);
	console.log(x, y, z, ", index : ", index);
});

