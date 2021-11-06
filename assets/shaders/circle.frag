#version 330 core

out vec4 frag_color;

//TODO: Define uniforms for the center and the radius
uniform vec2 center;
uniform float radius;

uniform vec4 inside_color = vec4(1.0, 0.0, 0.0, 1.0);
uniform vec4 outside_color = vec4(0.0, 0.0, 0.0, 1.0);

void main(){
    //TODO: Write code that will draw the circle

    /*  
        Calculate the distance by using the euclidean distance
        the point is considered inside the circle if the distance between it
        and the circle's center is less than or equal to the radius 
    */
    
    float dist = sqrt(
        (gl_FragCoord.x - center[0]) * (gl_FragCoord.x - center[0]) 
        + (gl_FragCoord.y - center[1]) * (gl_FragCoord.y - center[1])
    );

    if (dist <= radius)
        frag_color = inside_color;
    else
        frag_color = outside_color;
}