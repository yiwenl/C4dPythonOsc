precision highp float;
attribute vec3 aVertexPosition;
attribute vec3 aPosOffset;

uniform mat4 uModelMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

uniform sampler2D textureCurr;
uniform sampler2D textureNext;
uniform sampler2D textureExtra;
uniform float percent;
uniform float time;
varying vec4 vColor;


vec2 rotate(vec2 v, float a) {
	float s = sin(a);
	float c = cos(a);
	mat2 m = mat2(c, -s, s, c);
	return m * v;
}

const float PI = 3.141592657;

void main(void) {
	vec2 uv      = aVertexPosition.xy;
	vec3 posCurr = texture2D(textureCurr, uv).rgb;
	vec3 posNext = texture2D(textureNext, uv).rgb;
	vec3 pos     = mix(posCurr, posNext, percent);
	vec3 extra   = texture2D(textureExtra, uv).rgb;

	vec3 posOffset = aPosOffset;
	

	float radius = length(pos);
	float ry = atan(pos.z, pos.x);
	float r = length(pos.xz);
	float rx = atan(pos.y, r);

	posOffset *= (sin(extra.b) * .5 + .5 ) * 2.0;
	posOffset.yz = rotate(posOffset.yz, rx);
	posOffset.xz = rotate(posOffset.xz, -ry+PI * .5);
	

	pos += posOffset;

	gl_Position  = uProjectionMatrix * uViewMatrix * uModelMatrix * vec4(pos, 1.0);
	
	float g 	 = sin(extra.r + time * mix(extra.b, 1.0, .5));
	g 			 = smoothstep(0.0, 1.0, g);
	g 			 = mix(g, 1.0, .5);
	vColor       = vec4(vec3(g), 1.0);
}