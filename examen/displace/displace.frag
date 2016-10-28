#version 330 core

in vec4 frontColor;
in vec3 vVertex;
out vec4 fragColor;

void main()
{
	vec3 tanX = dFdx(vVertex);
  vec3 tanY = dFdy(vVertex);
  vec3 normal = cross(tanX,tanY);
	vec3 N = normalize(normal);
  fragColor = vec4(N.z);
}
