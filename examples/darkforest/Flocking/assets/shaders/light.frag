
varying vec3 vNormal;

//
float diffuse(vec3 N, vec3 L) {
    return max(dot(N, normalize(L)), 0.0);
}


const vec3 LIGHT = vec3(1.0, 1.5, 2.0);

void main(void) {
    float d = diffuse(vNormal, LIGHT) + .2;
    gl_FragColor = vec4(vec3(d), 1.0);
}