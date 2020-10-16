// a simple flat color shader
#version 410

in vec4 vColor;
in vec2 vTexCoord;

uniform sampler2D diffuseTexture;

out vec4 FragColor;

void main()
{
	// float color = (vertexColor.x + vertexColor.y + vertexColor.z) / 3;
	FragColor = vColor;
	//FragColor = texture(diffuseTexture, vTexCoord);
}