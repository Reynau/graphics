#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform vec2 Min=vec2(-1,-1);
uniform vec2 Max=vec2(1,1);

vec2 uvunfold () {
  vec2 absBound = Max - Min;
  float s = mod((texCoord.s - Min.s),absBound.s) - 1;
  float t = mod((texCoord.t - Min.t),absBound.t) - 1;
  return vec2(s,t);
}


void main()
{
    vec3 N = normalize(normalMatrix * normal);
    frontColor = vec4(color,1.0);
    vtexCoord = texCoord;
    gl_Position = vec4(vtexCoord, 0.0, 1.0);
}
