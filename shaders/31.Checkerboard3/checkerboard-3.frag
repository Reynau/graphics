#version 330 core

in vec4 frontColor;
in vec2 vtexCoord;
out vec4 fragColor;

uniform float n = 8;

vec4 grey = vec4(0.8,0.8,0.8,1.0);
vec4 black = vec4(0.0,0.0,0.0,1.0);

void main()
{
  fragColor = grey;
  float part = 1/n;
  
  if (fract(vtexCoord.s / part) < 0.1) fragColor = black;
  if (fract(vtexCoord.t / part) < 0.1) fragColor = black;
}
