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


mat4 rotationMatrix(vec3 axis, float angle) {
    axis = normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;
    
    return mat4(oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,  0.0,
                oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,  0.0,
                oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c,           0.0,
                0.0,                                0.0,                                0.0,                                1.0);
}

const float PI = 3.141592657;

void main(void) {
	vec2 uv        = aVertexPosition.xy;
	vec3 posCurr   = texture2D(textureCurr, uv).rgb;
	vec3 posNext   = texture2D(textureNext, uv).rgb;
	vec3 pos       = mix(posCurr, posNext, percent);
	vec3 extra     = texture2D(textureExtra, uv).rgb;
	
	vec3 posOffset = aPosOffset;
	
	vec3 right     = vec3(1.0, 0.0, 0.0);
	vec3 dir       = normalize(posNext - posCurr);
	vec3 axis      = cross(dir, right);
	float theta    = acos(dot(right, dir));
	mat4 m         = rotationMatrix(axis, theta);
	posOffset      = (m * vec4(aPosOffset, 1.0)).rgb;
	
	
	vec3 N         = (m * vec4(0.0, 0.0, -1.0, 1.0)).rgb;
	pos            += posOffset;
	
	gl_Position    = uProjectionMatrix * uViewMatrix * uModelMatrix * vec4(pos, 1.0);
	vec3 L         = normalize(vec3(1.0, 1.0, -1.0));
	float g        = max(dot(N, L), 0.0);
	g              = mix(g, 1.0, .25);
	vColor         = vec4(vec3(g), 1.0);
}