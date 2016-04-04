// index.js
'use strict';
const PORT_SOCKET = 9876;
let app    = require('express')();
let server = app.listen(PORT_SOCKET);
let io     = require('socket.io')(server);


//	OSC EMITTER

const PORT_EMIT_OSC = 8885;
const OscEmitter = require("osc-emitter");

let emitter = new OscEmitter();
emitter.add('localhost', PORT_EMIT_OSC);
emitter.add('localhost', PORT_EMIT_OSC+1);


//	WEB SOCKETS

io.on('connection', (socket)=>_onConnected(socket));

function _onConnected(socket) {
	console.log('A user is connected : ', socket.id);

	socket.on('disconnect', ()=>_onDisconnected() );
	socket.on('test', (o)=>_onTest(o) );
	socket.on('particlePosition', (positions)=>_onParticlePositions(positions));
}


function _onDisconnected() {
	console.log('User disconnected');
}


function _onTest(o) {
	console.log('on Test : ', o);
}


function _onParticlePositions(positions) {
	
	// emitter.emit('/positions', positions[0], positions[1], positions[2], positions[3]);
	let num = positions.length /3;
	console.log('On Position:', num);
	for(let i=0; i<num; i++) {
		emitter.emit('/positions', positions[i*3], positions[i*3+1], positions[i*3+2], i);
	}
}

/*
//	OSC RECEIVER

const PORT_OSC = 7110;
const OscReceiver = require("osc-receiver");

let receiver = new OscReceiver();
receiver.bind(PORT_OSC);


//	OSC MESSAGES HANDLING

receiver.on('/cameraPos', function(x, y, z) {
	console.log('Camera Position : ', x, y, z);
	io.emit('cameraPosition', {x:-x, y:y, z:z})
});

receiver.on('/lightPos', function(x, y, z) {
	console.log('Light Position : ', x, y, z);
	io.emit('lightPosition', {x:-x, y:y, z:z})
});

*/

