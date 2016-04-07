
varying vec3 vNormal;

uniform vec3 position;
uniform vec3 scale;

void main() {
    gl_TexCoord[0]  = gl_MultiTexCoord0;
    vec4 pos        = gl_Vertex;
    pos.xyz         = pos.xyz * scale + position;

    gl_Position     = gl_ModelViewProjectionMatrix * pos;
    vNormal        = gl_Normal;
}