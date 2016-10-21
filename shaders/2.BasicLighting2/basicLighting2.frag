#version 330 core

in vec4 frontColor;
in vec3 vNormal;
out vec4 fragColor;

void main()
{
	vec3 normal = normalize(vNormal);
    fragColor = frontColor * normal.z;
}
