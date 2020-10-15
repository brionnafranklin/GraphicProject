// a simple shader
#version 410

layout( location = 0 ) in vec4 aPosition;
layout( location = 1 ) in vec4 aColor;
layout( location = 2 ) in vec2 aTexCoord;

out vec4 vColor;
out vec2 vTexCoord;

uniform mat4 ProjectionViewModel;
uniform float timePassed;

void main() 
{
	vColor = aColor;
		// gl_Position = ProjectionViewModel * vec4(aPosition.x, sin(timePassed), aPosition.z, aPosition.w);
	vTexCoord = aTexCoord;
	gl_Position = ProjectionViewModel * aPosition;
}