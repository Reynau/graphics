#version 330 core

in vec4 frontColor;
in vec2 vtexCoord;
out vec4 fragColor;

uniform sampler2D noise0;
uniform sampler2D rock1;
uniform sampler2D grass2;

void main()
{
  vec4 rockColor = texture(rock1, vtexCoord);
  vec4 grassColor = texture(grass2, vtexCoord);
  vec4 noise = texture(noise0, vtexCoord);
  fragColor = mix(rockColor, grassColor, noise.r);
}
