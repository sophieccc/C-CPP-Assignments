void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord;
	vec3 black = vec3(0.0);
    vec3 pixel = vec3(1.0);
	vec2 centre = iResolution.xy/2.0;
    
    float dist = length(centre - uv);
    if(mod(dist,20.0)<4.0) pixel = black;
    
    fragColor = vec4(pixel,1.0);
    
}