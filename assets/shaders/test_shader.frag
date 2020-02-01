uniform vec2 location[64];
uniform float power[64];
uniform vec4 color[64];

uniform float data_size;

void main(void)
{
    vec4 finalColor = gl_Color;

    for (int i = 0; i < 2; i++) {
        //float distance = length(location[i] - gl_FragCoord.xy) + power[i];
        //float attenuation = power[i] / distance;
        //vec4 color = vec4(attenuation, attenuation, attenuation, 4) * color[i];
        //finalColor *= color;

        float distance = length(location[i] - gl_FragCoord.xy) + 20.0;

        finalColor *= color[i] * power[i] / distance;
    }

    gl_FragColor = finalColor;
}