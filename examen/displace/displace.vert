#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;
out vec3 vVertex;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;

uniform sampler2D heightMap;

uniform float scale = 0.05;

void main()
{
	vec2 st = 0.49 * vertex.xy + vec2(0.5);
	vec4 heigth = texture(heightMap, st);
	float r = heigth.r;
	float d = scale * r;
	vec3 newPos = vertex + normal*d;
	vVertex = (modelViewMatrix * vec4(newPos,1.0)).xyz;

	gl_Position = modelViewProjectionMatrix * vec4(newPos.xyz, 1.0);
}
