const vs = require('./basic.vert');
const fs = require('./basic.frag');
const PORT_SOCKET = 9876;
const TARGET_SERVER_IP = '192.168.10.30:'+PORT_SOCKET;
const socket = require('./libs/socket.io-client')(TARGET_SERVER_IP);

import './global.scss';
import alfrid from 'alfrid';

let camera, mesh, shader, bAxis;
let GL = alfrid.GL;
let lightPosition = [0, 1, 1];

window.addEventListener('load', _init);


function _init() {
	let canvas = document.createElement("canvas");
	document.body.appendChild(canvas);
	canvas.className = 'Main-Canvas';

	//	INIT GL TOOL
	GL.init(canvas);


	//	CAMREA
	camera = new alfrid.CameraPerspective();
	camera.setPerspective(Math.PI/2, GL.aspectRatio, 1, 10000);
	camera.lookAt([0, 0, 10], [0, 0, 0], [0, 1, 0]);

	//	HELPER
	bAxis = new alfrid.BatchAxis();

	//	MESH
	mesh = alfrid.Geom.sphere(1, 24, true);

	//	SHADER
	shader = new alfrid.GLShader(vs, fs);

	//	LOOPING
	alfrid.Scheduler.addEF(loop);
}



function loop() {
	GL.clear(0, 0, 0, 0);
	GL.setMatrices(camera);
	bAxis.draw();

	shader.bind();
	shader.uniform("lightPosition", "vec3", lightPosition);
	GL.draw(mesh);
}


//	WEBSOCKETS COMM

socket.on('cameraPosition', (pos)=>_onCameraPosition(pos));
socket.on('lightPosition', (pos)=>_onLightPosition(pos));

function _onCameraPosition(pos) {
	camera.lookAt([pos.x, pos.y, pos.z], [0, 0, 0], [0, 1, 0]);
}


function _onLightPosition(pos) {
	console.log('on Light : ', pos);
	lightPosition = [pos.x, pos.y, pos.z];
}