import '../scss/global.scss';
import alfrid , { Camera } from 'alfrid';
import SceneApp from './SceneApp';
import AssetsLoader from 'assets-loader';
import dat from 'dat-gui';

const GL = alfrid.GL;
const assets = [];
window.params = {
	numParticles:32,
	skipCount:1,
	maxRadius: 2.5,
	minRadius: 0.25,
	rotationSpeed:0.0175,
	noiseSpeed:0.02
}

if(document.body) {
	_init();
} else {
	window.addEventListener('DOMContentLoaded', _init);	
}


function _init() {

	//	LOADING ASSETS
	if(assets.length > 0 ) {
		document.body.classList.add('isLoading');

		let loader = new AssetsLoader({
			assets:assets
		}).on('error', function(error) {
			console.error(error);
		}).on('progress', function(p) {
			// console.log('Progress : ', p);
			let loader = document.body.querySelector('.Loading-Bar');
			if(loader) loader.style.width = (p * 100).toFixed(2) + '%';
		}).on('complete', _onImageLoaded)
		.start();	
	} else {
		_init3D();
	}

}


function _onImageLoaded(o) {

	//	ASSETS
	console.log('Image Loaded : ', o);
	document.body.classList.remove('isLoading');
	window.assets = o;	

	_init3D();
}


function _init3D() {

	//	CREATE CANVAS
	let canvas = document.createElement("canvas");
	canvas.className = 'Main-Canvas';
	document.body.appendChild(canvas);

	//	INIT 3D TOOL
	GL.init(canvas);

	//	CREATE SCENE
	let scene = new SceneApp();

	//	INIT DAT-GUI
	window.gui = new dat.GUI({width:300});
	gui.add(params, 'maxRadius', 0.0, 10.0);
	gui.add(params, 'minRadius', 0.0, 1.0);
	gui.add(params, 'rotationSpeed', 0.0, 0.1);
	gui.add(params, 'noiseSpeed', 0.0, 0.1);

}