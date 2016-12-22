#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform vec3 boundingBoxMin;
uniform vec3 boundingBoxMax;
uniform mat4 modelViewProjectionMatrix;

in vec3 vVertex[];
in vec3 vNormal[];

uniform float speed = 0.5;
uniform float angSpeed = 8.0;
uniform float time;

void main( void )
{
  float a = time * angSpeed;
  
  vec3 T = speed*time*(vNormal[0] + vNormal[1] + vNormal[2])/3.0;
  mat3 Rz = mat3(vec3( cos(a),  sin(a), 0),
                 vec3(-sin(a),  cos(a), 0),
                 vec3(      0,       0, 1));

  vec3 baricenter = (vVertex[0] + vVertex[1] + vVertex[2]) / 3;

  for( int i = 0 ; i < 3 ; i++ ) {
    vec3 v = (vVertex[i] - baricenter) * Rz + baricenter;
    gfrontColor = vfrontColor[i];
    gl_Position = modelViewProjectionMatrix * vec4(v + T,1.0);
    EmitVertex();
  }
  EndPrimitive();
}

