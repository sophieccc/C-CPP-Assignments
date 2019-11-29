void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord;
	vec3 linesColour = vec3(0.0, 0.0, 0.0);
    vec3 pixel = vec3(1.0, 1.0, 1.0);

    if(mod(uv.x,20.0)<1.0) pixel = linesColour;

    // Output to screen
    fragColor = vec4(pixel,1.0);
}