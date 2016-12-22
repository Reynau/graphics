#version 330 core

in vec4 frontColor;
in vec2 vtexCoord;
out vec4 fragColor;

vec4 red = vec4(1.0,0.0,0.0,1.0);
vec4 yellow = vec4(1.0,1.0,0.0,1.0);

void main()
{
  float f = fract(vtexCoord.s);
  float a = 0.1111111111111111;
  fragColor = red;
  float part = f / a;
  if (part >= 0.0 && part < 1.0 ||
      part >= 2.0 && part < 3.0 ||
      part >= 4.0 && part < 5.0 ||
      part >= 6.0 && part < 7.0 ||
      part >= 8.0 && part < 9.0) fragColor = yellow;
}
