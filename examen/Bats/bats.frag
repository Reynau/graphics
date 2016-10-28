#version 330 core

in vec4 frontColor;
out vec4 fragColor;

uniform sampler2D bat0;
uniform sampler2D bat1;

uniform float time;

void main()
{
	vec2 batCoords = gl_FragCoord.xy / 64 - vec2(time);
	float decSeg = fract(time);
	float part = 0.1;
	vec4 C;
	if (decSeg / part < 0.5) C = texture(bat0, batCoords);
	else C = texture(bat1, batCoords);
	if (C.a > 0.2) fragColor = vec4(0.0);
	else fragColor = frontColor;
}
