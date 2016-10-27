#version 330 core

in vec4 frontColor;
in vec2 vtexCoord;
out vec4 fragColor;

vec4 white = vec4(1.0);
vec4 red = vec4(1.0,0.0,0.0,0.0);

void main()
{
  fragColor = white;
  vec2 centerToPoint = vtexCoord - vec2(0.5,0.5);
  if (length(centerToPoint) <= 0.2) fragColor = red;
}
