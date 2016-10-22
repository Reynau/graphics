#version 330 core

in vec4 frontColor;
in vec3 vVertex;
in vec3 vNormal;
out vec4 fragColor;

uniform vec4 lightAmbient;
uniform vec4 lightDiffuse;
uniform vec4 lightSpecular;
uniform vec4 lightPosition; // Eye space

uniform vec4 matAmbient;
uniform vec4 matDiffuse;
uniform vec4 matSpecular;
uniform float matShininess;

vec4 calculate_phong() {
  vec3 P = normalize(vVertex);
	vec3 V = normalize(-P);
  vec3 N = normalize(vNormal);
	vec3 L = normalize(lightPosition.xyz - P);
	float NL = max(0.0, dot(N,L));
	vec3 R = normalize(2*NL*N-L);
	float RV = max(0.0, dot(R,V));

	vec4 KaIa = matAmbient * lightAmbient;
	vec4 KdId = matDiffuse * lightDiffuse;
	vec4 KsIs = matSpecular * lightSpecular;
	
	return KaIa + KdId*NL + KsIs*pow(RV,matShininess);
}
void main()
{
    fragColor = calculate_phong();
}
