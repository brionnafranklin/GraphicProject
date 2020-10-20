// classic Phong fragment shader
#version 410

in vec3 vNormal;
in vec4 vColor;
in vec2 vTexCoord;

uniform vec3 LightDirection;

out vec4 FragColour;

void main() 
{
	// ensure normal and light direction are normalized
	vec3 N = normalize(vNormal);
	vec3 L = normalize(LightDirection);

	// calculate lambert term (negate light direction)
	float lambertTerm = max( 0, min( 1, dot( N, -L ) ) );

	// output lambert as grayscale
	FragColour = vColor + vec4( lambertTerm, lambertTerm, lambertTerm, 1 );
}