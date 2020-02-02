uniform sampler2D texture;

uniform vec2 first;
uniform vec2 second;
uniform vec2 third;

void main()
{

    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
/*
    float distance = length(first - gl_FragCoord.xy) + 200.0;
    float attenuation = 300.0 / distance;
    vec4 color = vec4(attenuation, attenuation, attenuation, 1) * vec4(1, 0.6, 0.8, 1);

    float distance2 = length(location2 - gl_FragCoord.xy) + 200.0;
    float attenuation2 = 300.0 / distance2;
    vec4 color2 = vec4(attenuation2, attenuation2, attenuation2, 1) * vec4(1, 0.6, 0.8, 1);

    float distance3 = length(third - gl_FragCoord.xy) + 200.0;
    float attenuation3 = 300.0 / distance3;
    vec4 color3 = vec4(attenuation3, attenuation3, attenuation3, 1) * vec4(1, 0.6, 0.8, 1);
*/
    gl_FragColor = pixel;

}