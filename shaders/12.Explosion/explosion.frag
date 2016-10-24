#version 330 core

in vec4 frontColor;
in vec2 vtexCoord;
out vec4 fragColor;

uniform sampler2D explosion;

uniform float time;

const float slice = 0.033333;

void main()
{
  int frame = int(time/slice);
  float fila = floor(frame/8) + 1;
  float col = floor(mod(frame,8));
  vec2 offset = vec2(col*0.125, 1-fila*0.166666666666667);
  vec2 escalat = vec2(vtexCoord.s/8, vtexCoord.t/6);
  vec2 newCoord = escalat + offset;
  vec4 color = texture(explosion, newCoord);
  fragColor = color.a * color;
}
