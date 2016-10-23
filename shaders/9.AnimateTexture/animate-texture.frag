#version 330 core

in vec4 frontColor;
in vec2 vtexCoord;
out vec4 fragColor;

uniform sampler2D colorMap;
uniform float speed=0.1;
uniform float time;

void main()
{
  vec2 texcoord = vec2(vtexCoord.s + speed*time, vtexCoord.t + speed*time); 
  fragColor = frontColor * texture(colorMap, texcoord);
}
