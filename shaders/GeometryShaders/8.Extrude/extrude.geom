#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
in vec3 vNormal[];
out vec4 gfrontColor;
out vec3 gNormal;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
uniform float d = 0.5;

void pintaVertex(vec3 v, vec3 n) {
	gNormal = normalMatrix * n;
	gl_Position = modelViewProjectionMatrix * vec4(v, 1.);
	EmitVertex();
}

void pintarTriangle(vec3 v1, vec3 v2, vec3 v3, vec3 n) {
	pintaVertex(v1, n);
	pintaVertex(v2, n);
	pintaVertex(v3, n);
	EndPrimitive();
}

void pintarCara(vec3 v1, vec3 v2, vec3 v3, vec3 v4, vec3 n) {
	pintaVertex(v1, n);
	pintaVertex(v2, n);
	pintaVertex(v3, n);
	pintaVertex(v4, n);
	EndPrimitive();
}

vec3 calcularNormal(vec3 v1, vec3 v2, vec3 v3) {
	vec3 P = v2 - v1;
	vec3 Q = v3 - v1;
	return cross(P,Q);
}

void main( void )
{
	vec3 N = normalize((vNormal[0] + 
						vNormal[1] + 
						vNormal[2]) / 3);

	vec3 v1 = gl_in[0].gl_Position.xyz;
	vec3 v2 = gl_in[1].gl_Position.xyz;
	vec3 v3 = gl_in[2].gl_Position.xyz;
	vec3 v4 = v1 + d*N;
	vec3 v5 = v2 + d*N;
	vec3 v6 = v3 + d*N;
	
	vec3 n;

	pintarTriangle(v1, v3, v2, -N);	// Back
	pintarTriangle(v4, v5, v6, N);	// Front
	
	n = normalize(calcularNormal(v1, v2, v4));
	pintarCara(v1, v2, v4, v5, n);	// Top

	n = normalize(calcularNormal(v1, v4, v3));
	pintarCara(v1, v3, v4, v6, n);	// Left

	n = normalize(calcularNormal(v2, v3, v5));
	pintarCara(v2, v3, v5, v6, n);	// Front
	
}
