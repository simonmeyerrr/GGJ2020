uniform vec2 lightLocation;


void main(void)
{
    float distance = length(lightLocation - gl_FragCoord.xy) + 50.0;
    float attenuation = 100.0 / distance;
    vec4 color = vec4(attenuation, attenuation, attenuation, 1) * vec4(0.5, 0.5, 0.5, 1);

    gl_FragColor = gl_Color * color;
}