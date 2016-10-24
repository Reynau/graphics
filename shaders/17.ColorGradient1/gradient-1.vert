#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform vec3 boundingBoxMin;
uniform vec3 boundingBoxMax;

const vec3 red = vec3(1.0,0.0,0.0);
const vec3 yellow = vec3(1.0,1.0,0.0);
const vec3 green = vec3(0.0,1.0,0.0);
const vec3 cian = vec3(0.0,1.0,1.0);
const vec3 blue = vec3(0.0,0.0,1.0);

void main()
{
  vec3 maxBounds = boundingBoxMax - boundingBoxMin;
  vec3 absVertex = vertex - boundingBoxMin;
  float fr = fract(absVertex.y/maxBounds.y);
  vec3 interp = mix(red, yellow, fr);

  vec3 N = normalize(normalMatrix * normal);
  frontColor = vec4(interp,1.0) * N.z;
  vtexCoord = texCoord;
  gl_Position = modelViewProjectionMatrix * vec4(vertex.xyz, 1.0);
}
