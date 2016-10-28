#version 330 core

in vec2 vtexCoord;
out vec4 fragColor;

uniform sampler2D foot0;
uniform sampler2D foot1;
uniform sampler2D foot2;
uniform sampler2D foot3;

const float R = 80.0;

uniform int layer = 2;

uniform vec2 mousePosition;
uniform bool virtualMouse = false;
uniform float mouseX, mouseY; 

vec2 mouse()
{
	if (virtualMouse) return vec2(mouseX, mouseY);
	else return mousePosition;
}

void main()
{
	// a completar. Recorda usar mouse() per obtenir les coords del mouse, en window space
	// 1. Calcular distància
	vec2 mouse = mouse();
	float d = length(mouse - gl_FragCoord.xy);
	// 2.
	vec4 C = texture(foot0, vtexCoord);
	if (d >= R) fragColor = C;
	else {
		// 3.
		vec4 D;
		if(layer == 0) D = texture(foot0, vtexCoord);
		if(layer == 1) D = texture(foot1, vtexCoord);
		if(layer == 2) D = texture(foot2, vtexCoord);
		if(layer == 3) D = texture(foot3, vtexCoord);

		// 4.
		float fract = d / R;
		fragColor = mix(D,C,fract);
	}
}
