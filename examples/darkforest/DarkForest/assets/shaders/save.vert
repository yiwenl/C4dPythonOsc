
varying vec3 vColor;

void main() {
    gl_TexCoord[0]  = gl_MultiTexCoord0;
    vec4 pos        = vec4(gl_MultiTexCoord0.xy, 0.0, 1.0);
    vColor          = gl_Vertex.rgb;

    gl_Position     = gl_ModelViewProjectionMatrix * pos;
    gl_PointSize    = 1.0;
}