console.log('init');

const vs = require('./basic.vert');
const fs = require('./basic.frag');
const PORT_SOCKET = 9876;
const TARGET_SERVER_IP = '192.168.10.30:'+PORT_SOCKET;
let socket = require('./libs/socket.io-client')(TARGET_SERVER_IP);

import './global.scss';
import alfrid from 'alfrid';

console.log(alfrid);

let camera, mesh, shader, bAxis;
let GL = alfrid.GL;
let position = [0, 0, 10];
let lightPosition = [0, 1, 1];

window.addEventListener('load', _init);


function _init() {
	console.log('init');
	let canvas = document.createElement("canvas");
	document.body.appendChild(canvas);
	canvas.className = 'Main-Canvas';

	GL.init(canvas);


	//	CAMREA
	camera = new alfrid.CameraPerspective();
	camera.setPerspective(Math.PI/2, GL.aspectRatio, 1, 10000);
	camera.lookAt(position, [0, 0, 0], [0, 1, 0]);
	// new alfrid.OrbitalControl(camera, window, 10);

	bAxis = new alfrid.BatchAxis();

	//	mesh
	mesh = alfrid.Geom.sphere(1, 24, true);

	//	shader
	shader = new alfrid.GLShader(vs, fs);

	alfrid.Scheduler.addEF(loop);
}



function loop() {
	GL.clear(0, 0, 0, 0);
	GL.setMatrices(camera);
	bAxis.draw();

	shader.bind();
	shader.uniform("lightPosition", "vec3", lightPosition);
	GL.draw(mesh);
	// if(Math.random() > .9) console.log(camera.matrix);
	// if(Math.random() > .9) console.log(position);
}


socket.on('cameraPosition', (pos)=>_onCameraPosition(pos));
socket.on('lightPosition', (pos)=>_onLightPosition(pos));



function _onCameraPosition(pos) {
	position = [pos.x, pos.y, pos.z];
	camera.lookAt(position, [0, 0, 0], [0, 1, 0]);
}


function _onLightPosition(pos) {
	console.log('on Light : ', pos);
	lightPosition = [pos.x, pos.y, pos.z];
}