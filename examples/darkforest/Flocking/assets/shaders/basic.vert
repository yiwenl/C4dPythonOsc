
varying vec3 vNormal;

void main() {
    gl_TexCoord[0]  = gl_MultiTexCoord0;
    vec4 pos        = gl_Vertex;

    gl_Position     = gl_ModelViewProjectionMatrix * pos;
    vNormal        = gl_Normal;
}