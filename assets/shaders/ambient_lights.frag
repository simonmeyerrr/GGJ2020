uniform sampler2D texture;

uniform vec2 locations[64];
uniform vec4 colors[64];
uniform float powers[64];

uniform int light_number;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
    vec4 finalLighting = vec4(0.0, 0.0, 0.0, 1.0);

    for (int i = 0; i < light_number; ++i) {
        float distance = length(locations[i] - gl_FragCoord.xy) + (powers[i] / 1.6);
        float attenuation = powers[i] / distance;
        finalLighting += vec4(attenuation, attenuation, attenuation, 1) * colors[i];
    }

    gl_FragColor = finalLighting * pixel;
}