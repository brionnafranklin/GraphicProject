// classic Phong fragment shader
#version 410

in vec4 vPosition;
in vec3 vNormal;
in vec4 vColor;
in vec2 vTexCoord;

uniform vec3 Ka;
uniform vec3 Kd;
uniform vec3 Ks;
uniform float specularPower;

uniform vec3 Ia; // ambient light color
uniform vec3 Id; // diffuse light color
uniform vec3 Is; // specular light color
uniform vec3 LightDirection;

uniform vec3 CameraPosition;

vec4 LightColor;
vec4 TextureColor;

uniform sampler2D diffuseTexture;

out vec4 FragColour;

void main() 
{
	// ensure normal and light direction are normalized
	vec3 N = normalize(vNormal);
	vec3 L = normalize(LightDirection);

	// calculate lambert term (negate light direction)
	float lambertTerm = max( 0, min( 1, dot( N, -L ) ) );

	// calculate view vector and reflection vector
	vec3 V = normalize(CameraPosition - vPosition.xyz);
	vec3 R = reflect( L, N );

	// calculate specular term
	float specularTerm = pow( max( 0, dot( R, V ) ), specularPower );

	// output color
	vec3 ambient = ( Ka + vColor.rgb ) * Ia;
	vec3 diffuse = ( Kd + vColor.rgb ) * Id * lambertTerm;
	vec3 specular = Is * Ks * specularTerm;
	LightColor = vec4(ambient + diffuse + specular, 1.0f);

	TextureColor = texture(diffuseTexture, vTexCoord) + vColor;

	FragColour = (LightColor / 2) + (TextureColor / 3);
}