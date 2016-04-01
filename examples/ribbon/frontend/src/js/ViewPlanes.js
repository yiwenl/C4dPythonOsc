// ViewPlanes.js
import alfrid from 'alfrid';
let GL = alfrid.GL;
const vsPlane = require("../shaders/planes.vert");
const fsPlane = require("../shaders/planes.frag");
const random = function(min, max) { return min + Math.random() * (max - min);	};

class ViewPlanes extends alfrid.View {
	
	constructor() {
		super(vsPlane, fsPlane);
		this.time = 0;
	}


	_init() {
		let positions    = [];
		let posOffset    = [];
		let coords       = [];
		let indices      = []; 
		let count        = 0;
		let numParticles = params.numParticles;
		let ux, uy;

		const size = 0.1;

		for(let j=0; j<numParticles; j++) {
			for(let i=0; i<numParticles; i++) {
				ux = i/numParticles;
				uy = j/numParticles;

				let scale = random(2, 4);

				positions.push([ux, uy, 0]);
				positions.push([ux, uy, 0]);
				positions.push([ux, uy, 0]);
				positions.push([ux, uy, 0]);

				posOffset.push([-size * scale, -size, 0.0]);
				posOffset.push([ size * scale, -size, 0.0]);
				posOffset.push([ size * scale,  size, 0.0]);
				posOffset.push([-size * scale,  size, 0.0]);

				indices.push(count * 4 + 0);
				indices.push(count * 4 + 1);
				indices.push(count * 4 + 2);
				indices.push(count * 4 + 0);
				indices.push(count * 4 + 2);
				indices.push(count * 4 + 3);
				count ++;

			}
		}

		this.mesh = new alfrid.Mesh(GL.TRIANGLES);
		this.mesh.bufferVertex(positions);
		this.mesh.bufferIndices(indices);
		this.mesh.bufferData(posOffset, 'aPosOffset', 3);
	}


	render(textureCurr, textureNext, p, textureExtra) {
		this.time += 0.1;
		this.shader.bind();

		this.shader.uniform("textureCurr", "uniform1i", 0);
		textureCurr.bind(0);

		this.shader.uniform("textureNext", "uniform1i", 1);
		textureNext.bind(1);

		this.shader.uniform("textureExtra", "uniform1i", 2);
		textureExtra.bind(2);

		this.shader.uniform("percent", "float", p);
		this.shader.uniform("time", "float", this.time);
		GL.draw(this.mesh);
	}


}

export default ViewPlanes;