#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform float disp = 0.05;

void pintaVertex(vec4 v, vec4 c) {
	gfrontColor = c;
	gl_Position = v;
	EmitVertex();
}

vec3 calculaNormal (vec3 v1, vec3 v2, vec3 v3) {
	vec3 P = v2 - v1;
	vec3 Q = v3 - v1;
	vec3 X = cross(Q,P);
	return normalize(X);
}

void main( void )
{
	vec4 A = gl_in[0].gl_Position;
	vec4 B = gl_in[1].gl_Position;
	vec4 C = gl_in[2].gl_Position;

	vec3 NT = calculaNormal(A.xyz, B.xyz, C.xyz);

	vec4 D = vec4(disp * NT, 0);

	vec4 T = (A + B + C) / 3 + D;

	vec4 AC = vfrontColor[0];
	vec4 BC = vfrontColor[1];
	vec4 CC = vfrontColor[2];
	vec4 TC = vec4(1.0);

	// ABT
	pintaVertex(A,AC);
	pintaVertex(B,BC);
	pintaVertex(T,TC);
	EndPrimitive();
	// CAT
	pintaVertex(C,CC);
	pintaVertex(A,AC);
	pintaVertex(T,TC);
	EndPrimitive();
	// BCT
	pintaVertex(B,BC);
	pintaVertex(C,CC);
	pintaVertex(T,TC);
	EndPrimitive();
}
