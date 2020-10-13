// a simple flat color shader
#version 410

out vec4 FragColor;
in vec4 vertexColor;

void main()
{
	float color = (vertexColor.x + vertexColor.y + vertexColor.z) / 3;
	FragColor = vertexColor;
}