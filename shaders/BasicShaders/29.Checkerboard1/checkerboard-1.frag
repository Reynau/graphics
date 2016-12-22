#version 330 core

in vec4 frontColor;
in vec2 vtexCoord;
out vec4 fragColor;

void main()
{
  fragColor = vec4(0.8,0.8,0.8,1.0);
  float part = 0.25;
  
  if (fract(vtexCoord.s / part) > 0.5 && fract(vtexCoord.t / part) < 0.5) fragColor = vec4(0.0,0.0,0.0,1.0);
  if (fract(vtexCoord.s / part) < 0.5 && fract(vtexCoord.t / part) > 0.5) fragColor = vec4(0.0,0.0,0.0,1.0);
}
