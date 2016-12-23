 #version 330 core

layout (location=0) in vec3 vertex;

uniform vec4 color;
uniform mat4 modelViewProjectionMatrix;
out vec4 vFrontColor;
void main() {
	vFrontColor=vec4(color);
  gl_Position=modelViewProjectionMatrix*(vec4(vertex, 1));
}

