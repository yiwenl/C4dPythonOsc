// SceneApp.js

import alfrid , { Scene } from 'alfrid';
import ViewAddVel from './ViewAddVel';
import ViewSave from './ViewSave';
import ViewRender from './ViewRender';
import ViewSim from './ViewSim';
import ViewPlanes from './ViewPlanes';

const GL = alfrid.GL;
const RENDER_INTERVAL = 500;

class SceneApp extends alfrid.Scene {
	constructor() {
		super();
		GL.enableAlphaBlending();
		GL.disable(GL.CULL_FACE);

		this._count = 0;
		this.orbitalControl.radius.value = 15;
		// this.orbitalControl.rx.value = 0.25;
		// this.orbitalControl.ry.value = 0.5;

		const numParticles = params.numParticles;
		const arraysize = numParticles * numParticles * 4;
		this._pixels = new Float32Array(arraysize);
		this._frame = 0;
	}

	_initTextures() {
		console.log('init textures');

		//	FBOS
		const numParticles = params.numParticles;
		const o = {
			minFilter:GL.NEAREST,
			magFilter:GL.NEAREST
		}

		this._fboCurrentPos = new alfrid.FrameBuffer(numParticles, numParticles, o);
		this._fboTargetPos  = new alfrid.FrameBuffer(numParticles, numParticles, o);
		this._fboCurrentVel = new alfrid.FrameBuffer(numParticles, numParticles, o);
		this._fboTargetVel  = new alfrid.FrameBuffer(numParticles, numParticles, o);
		this._fboExtra  	= new alfrid.FrameBuffer(numParticles, numParticles, o);


		window.setInterval( ()=>this._renderOnInterval(), RENDER_INTERVAL);
	}


	_initViews() {
		console.log('init views');
		
		//	helpers
		this._bCopy = new alfrid.BatchCopy();
		this._bAxis = new alfrid.BatchAxis();
		this._bDots = new alfrid.BatchDotsPlane();
		this._bBall = new alfrid.BatchBall();


		//	views
		this._vAddVel = new ViewAddVel();
		this._vRender = new ViewRender();
		this._vPlanes = new ViewPlanes();
		this._vSim 	  = new ViewSim();

		this._vSave = new ViewSave();
		GL.setMatrices(this.cameraOrtho);

		this._fboCurrentPos.bind();
		this._vSave.render(0);
		this._fboCurrentPos.unbind();

		this._fboExtra.bind();
		this._vSave.render(1);
		this._fboExtra.unbind();

		this._fboTargetPos.bind();
		this._bCopy.draw(this._fboCurrentPos.getTexture());
		this._fboTargetPos.unbind();

		GL.setMatrices(this.camera);
	}


	updateFbo() {
		//	Update Velocity : bind target Velocity, render simulation with current velocity / current position
		this._fboTargetVel.bind();
		GL.clear(0, 0, 0, 1);
		this._vSim.render(this._fboCurrentVel.getTexture(), this._fboCurrentPos.getTexture(), this._fboExtra.getTexture() );
		this._fboTargetVel.unbind();


		//	Update position : bind target Position, render addVel with current position / target velocity;
		this._fboTargetPos.bind();
		GL.clear(0, 0, 0, 1);
		this._vAddVel.render(this._fboCurrentPos.getTexture(), this._fboTargetVel.getTexture());
		this._fboTargetPos.unbind();

		//	SWAPPING : PING PONG
		let tmpVel          = this._fboCurrentVel;
		this._fboCurrentVel = this._fboTargetVel;
		this._fboTargetVel  = tmpVel;

		let tmpPos          = this._fboCurrentPos;
		this._fboCurrentPos = this._fboTargetPos;
		this._fboTargetPos  = tmpPos;

	}


	_renderOnInterval() {
		console.log('Render on Interval :');
	}

	render() {

		this._count ++;
		if(this._count % params.skipCount == 0) {
			this._count = 0;
			this.updateFbo();
		}

		let p = this._count/params.skipCount;

		GL.clear(0, 0, 0, 0);
		this._bAxis.draw();
		this._bDots.draw();

		this._vRender.render(this._fboTargetPos.getTexture(), this._fboCurrentPos.getTexture(), p, this._fboExtra.getTexture());
		// this._vPlanes.render(this._fboTargetPos.getTexture(), this._fboCurrentPos.getTexture(), p, this._fboExtra.getTexture());

		// const size = 128;
		// GL.viewport(0, 0, size, size);
		// this._bCopy.draw(this._fboExtra.getTexture());

		if(params.sendPositions) {
			this.readPositions();	
		}
		
	}


	readPositions() {
		console.log('Sending position:', this._frame);
		this._fboCurrentPos.bind();
		GL.gl.readPixels(0, 0, params.numParticles, params.numParticles, GL.gl.RGBA, GL.gl.FLOAT, this._pixels);
		this._fboCurrentPos.unbind();
		// params.sendPositions = false;

		let positions = [];
		for(let i=0; i<this._pixels.length; i+=4) {
			positions.push(this._pixels[i]);
			positions.push(this._pixels[i+1]);
			positions.push(this._pixels[i+2]);
		}

		socket.emit('particlePosition', positions, this._frame);
		this._frame ++;
	}


	resize() {
		GL.setSize(window.innerWidth, window.innerHeight);
		this.camera.setAspectRatio(GL.aspectRatio);
	}
}


export default SceneApp;