#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform mat4 modelViewProjectionMatrix;
uniform vec3 boundingBoxMin;
uniform vec3 boundingBoxMax;

void main( void )
{
  if (gl_PrimitiveIDIn==0) { 
    float R=length(boundingBoxMax-boundingBoxMin)/2;
    vec3 RC=(boundingBoxMax+boundingBoxMin)/2;
    RC.y=boundingBoxMin.y-0.01;
    gfrontColor = vec4(0,1,1,1);
    
    gl_Position=modelViewProjectionMatrix*vec4(RC.x+R,RC.y,RC.z+R, 1);
    EmitVertex();

    gl_Position=modelViewProjectionMatrix*vec4(RC.x+R,RC.y,RC.z-R, 1);
    EmitVertex();

    gl_Position=modelViewProjectionMatrix*vec4(RC.x-R,RC.y,RC.z+R, 1);
    EmitVertex();

    gl_Position=modelViewProjectionMatrix*vec4(RC.x-R,RC.y,RC.z-R, 1);
    EmitVertex();

    EndPrimitive();
  }
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
		EmitVertex();
	}
  EndPrimitive();
  
  for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vec4(0.0);
		vec4 orPos = gl_in[i].gl_Position;
		vec4 shadowPos = vec4(orPos.x, boundingBoxMin.y, orPos.z, 1.0);
		gl_Position = modelViewProjectionMatrix * shadowPos;
		EmitVertex();
	}
  EndPrimitive();
}
