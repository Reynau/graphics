#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
in vec3 vVertex[];
out vec4 gfrontColor;
out vec3 gnormal;
out float gtop;
out vec2 gtexcoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
uniform float step = 0.05;

vec3 center;
vec4 color = vec4((vfrontColor[0]+vfrontColor[1]+vfrontColor[2])/3);

const vec4 LIGHT_GREY=vec4(.9,.9,.9,1);
 
void pintaVertex(vec3 v) {
	gtexcoord = vec2(v.z,v.x);
	gl_Position = modelViewProjectionMatrix * vec4(center + step * v, 1);
	EmitVertex();
}

void pintarCara(vec3 v1, vec3 v2, vec3 v3, vec3 v4, vec4 color, vec3 normal) {
	gfrontColor = color;
	gnormal = normal;
	pintaVertex(v1);
	pintaVertex(v2);
	pintaVertex(v3);
	pintaVertex(v4);
	EndPrimitive();
}

void main( void )
{
	center = (vVertex[0]+vVertex[1]+vVertex[2])/3;
	center = round(center/step)*step;

	vec4 color = (vfrontColor[0]+vfrontColor[1]+vfrontColor[2])/3;

	vec3 v1 = vec3(-0.5,  0.5,  0.5), v2 = vec3(0.5,  0.5,  0.5),
		 v3 = vec3(-0.5, -0.5,  0.5), v4 = vec3(0.5, -0.5,  0.5),
		 v5 = vec3(-0.5, -0.5, -0.5), v6 = vec3(0.5, -0.5, -0.5),
		 v7 = vec3(-0.5,  0.5, -0.5), v8 = vec3(0.5,  0.5, -0.5);

	vec3 N;

	gtop = 0;
	// Front 
	N = normalMatrix*vec3(0,0,-1);
	pintarCara(v6,v8,v5,v7,color,N);

	// Back
	N = normalMatrix*vec3(0,0,1);
	pintarCara(v1,v2,v3,v4,color,N);

	// Right
	N = normalMatrix*vec3(1,0,0);
	pintarCara(v2,v4,v8,v6,color,N);

	// Left
	N = normalMatrix*vec3(-1,0,0);
	pintarCara(v7,v1,v5,v3,color,N);

	// Top
	gtop = 1; 
	N = normalMatrix*vec3(0,1,0);
	pintarCara(v1,v2,v7,v8,color,N);

	// Bot
	N = normalMatrix*vec3(0,-1,0);
	pintarCara(v3,v4,v5,v6,color,N);
}
