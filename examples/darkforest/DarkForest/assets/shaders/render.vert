#version 120

uniform sampler2D texture;
uniform sampler2D textureExtra;

varying vec4 vColor;

void main() {
    vec2 uv         = gl_Vertex.xy;
    vec3 pos        = texture2D(texture, uv).rgb;
    gl_Position     = gl_ModelViewProjectionMatrix * vec4(pos, 1.0);
    vColor          = vec4(1.0, 1.0, 1.0, 1.0);
    vec3 extra      = texture2D(textureExtra, uv).rgb;
    
    gl_PointSize    = 1.0 + pow(2.0, extra.x * 3.0);
}