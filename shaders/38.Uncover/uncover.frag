#version 330 core

in vec4 frontColor;
in vec3 ndcVertex;
out vec4 fragColor;

uniform float time;

void main()
{
  float s = ndcVertex.s + 1.0;
  if (s > time) discard;
  fragColor = vec4(0.0,0.0,1.0,1.0);
}
