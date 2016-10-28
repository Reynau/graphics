#version 330 core

in vec4 frontColor;
in vec3 vNormal;
in vec2 vtexCoord;
out vec4 fragColor;

uniform sampler2D window;
uniform sampler2D interior1;
uniform sampler2D exterior2;

void main()
{
	vec4 C = texture(window, vtexCoord);
	float alpha = C.a;
	
	if (alpha == 1.0) fragColor = C;
	if (alpha < 1.0) {
		vec2 dCoords = vtexCoord + 0.5*vNormal.xy;
		vec4 D = texture(interior1, dCoords);
		if (D.a == 1.0) {
			fragColor = D;
		}
		else {
			vec2 eCoords = vtexCoord + 0.7*vNormal.xy;
			fragColor = texture(exterior2, eCoords);
		}
	}
}
