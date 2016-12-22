#version 330 core

in vec4 gfrontColor;
in vec3 gNormal;
out vec4 fragColor;

void main()
{
	vec3 N = normalize(gNormal);
    fragColor = vec4(N.z);
}
