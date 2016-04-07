uniform sampler2D texturePos;
uniform sampler2D textureVel;

void main(void) {
    vec2 uv = gl_TexCoord[0].st;
    vec3 pos = texture2D(texturePos, uv).rgb;
    vec3 vel = texture2D(textureVel, uv).rgb;
    
    gl_FragColor = vec4(pos + vel, 1.0);
}