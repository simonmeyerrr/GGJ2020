uniform vec2 lightLocation;

void main(void)
{
    float distance = length(lightLocation - gl_FragCoord.xy);
    float attenuation = 100.0 / distance;
    vec4 color = vec4(attenuation, attenuation, attenuation, 4) * vec4(230.0 / 255.0, 167.0 / 255.0, 73.0 / 255.0, 1);
    gl_FragColor = gl_Color * color;
}