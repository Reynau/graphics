#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
in vec3 vVertex[];
out vec4 gfrontColor;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
uniform float step = 0.2;

vec3 center;
vec4 color = vec4((vfrontColor[0]+vfrontColor[1]+vfrontColor[2])/3);

const vec4 LIGHT_GREY=vec4(.9,.9,.9,1);
 
void pintarCara(vec3 v1, vec3 v2, vec3 v3, vec3 v4, vec3 ilum) {
  vec4 C = vec4(center, 1.0);
  gfrontColor = LIGHT_GREY*ilum.z;
  gl_Position = modelViewProjectionMatrix * vec4(v1,1); EmitVertex();
  gl_Position = modelViewProjectionMatrix * vec4(v2,1); EmitVertex();
  gl_Position = modelViewProjectionMatrix * vec4(v3,1); EmitVertex();
  gl_Position = modelViewProjectionMatrix * vec4(v4,1); EmitVertex();
  EndPrimitive();
}

void main( void )
{
  center = (vVertex[0]+vVertex[1]+vVertex[2])/3;
  center /= step;
  center.x = round(center.x);
  center.y = round(center.y);
  center.z = round(center.z);
  center *= step;

  float s = step;
  vec3 v1 = center+vec3(-s,  s,  s), v2 = center+vec3( s,  s,  s),
       v3 = center+vec3(-s, -s,  s), v4 = center+vec3( s, -s,  s),
       v5 = center+vec3(-s, -s, -s), v6 = center+vec3( s, -s, -s),
       v7 = center+vec3(-s,  s, -s), v8 = center+vec3( s,  s, -s);

  pintarCara(v1,v2,v3,v4, vec3(normalMatrix*vec3( 0,  1,  0)));
  pintarCara(v6,v8,v5,v7, vec3(normalMatrix*vec3( 0, -1,  0)));
  pintarCara(v2,v4,v8,v6, vec3(normalMatrix*vec3( 1,  0,  0)));
  pintarCara(v7,v1,v5,v3, vec3(normalMatrix*vec3(-1,  0,  0)));
  pintarCara(v1,v2,v7,v8, vec3(normalMatrix*vec3( 0,  0,  1)));
  pintarCara(v3,v4,v5,v6, vec3(normalMatrix*vec3( 0,  0, -1)));
}
