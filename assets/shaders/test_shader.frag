uniform vec2 lightLocation;


void main(void)
{
    float distance = length(lightLocation - gl_FragCoord.xy);
    float attenuation = 50.0 / distance;
    vec4 color = vec4(attenuation, attenuation, attenuation, 1) * vec4(255.0 / 255.0, 167.0 / 255.0, 73.0 / 255.0, 1);

    gl_FragColor = gl_Color * color;
}