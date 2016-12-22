#version 330 core

in vec3 gNormal;
in vec3 gPos;
out vec4 fragColor;

uniform sampler2D grass_side0;
uniform sampler2D grass_top1;
uniform float d = 0.1;

void main() {
	vec3 N = normalize(gNormal);
	if (N.z == 0) { // Vertical
		vec2 tCoord = vec2(4 * (gPos.x - gPos.y), 1.0 - gPos.z / d);
		fragColor = texture2D(grass_side0, tCoord);
		if (fragColor.a < 0.1) discard;
	}
	else { // Horizontal
		vec2 tCoord = 4 * gPos.xy;
		fragColor = texture2D(grass_top1, tCoord);
	}
}