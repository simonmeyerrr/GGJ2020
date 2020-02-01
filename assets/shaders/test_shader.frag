uniform vec2 location[64];
uniform float power[64];
uniform vec4 color[64];

uniform float data_size;

void main(void)
{
<<<<<<< HEAD
    float distance = length(lightLocation - gl_FragCoord.xy) + 50.0;
    float attenuation = 100.0 / distance;
    vec4 color = vec4(attenuation, attenuation, attenuation, 1) * vec4(0.5, 0.5, 0.5, 1);
=======
    vec4 finalColor = gl_Color;
>>>>>>> 6811bedfa0e7109af759aa31045dfbf01d87bb5c

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