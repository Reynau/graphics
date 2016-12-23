#include "resaltat-objecte-seleccionat.h"
#include "glwidget.h"

using namespace std;

void ResaltatSeleccionat::loadShaders () {
  GLWidget &g = *glwidget();
  g.makeCurrent();

  vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
  vs->compileSourceFile("/home/xavi/Documents/University/G/viewer/plugins/resaltat-objecte-seleccionat/vertex.vert");

  fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
  fs->compileSourceFile("/home/xavi/Documents/University/G/viewer/plugins/resaltat-objecte-seleccionat/fragment.frag");

  program = new QOpenGLShaderProgram(this);
  program->addShader(vs);
  program->addShader(fs);
  program->link();
}

void ResaltatSeleccionat::onPluginLoad () {
	GLfloat coords[]={
    1, 1, 1,
    0, 1, 1,
    1, 0, 1,
    0, 0, 1,
    1, 0, 0,
    0, 0, 0,
    1, 1, 0,
    0, 1, 0,
    1, 1, 1,
    0, 1, 1,
    0, 1, 1,
    0, 1, 0,
    0, 0, 1,
    0, 0, 0,
    1, 0, 1,
    1, 0, 0,
    1, 1, 1,
    1, 1, 0
  };
  GLfloat colors[]={
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0
  };

	GLWidget &g = *glwidget();
  g.makeCurrent();

	// Create VAO & empty buffers
	g.glGenVertexArrays(1, &VAO);
	g.glBindVertexArray(VAO);
	
	// Coords
	g.glGenBuffers(1, &coordBufferID);
	g.glBindBuffer(GL_ARRAY_BUFFER, coordBufferID);
	g.glBufferData(GL_ARRAY_BUFFER, sizeof(coords), &coords[0], GL_STATIC_DRAW);
	g.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	g.glEnableVertexAttribArray(0);

	// Colors
	g.glGenBuffers(1, &colorBufferID);
	g.glBindBuffer(GL_ARRAY_BUFFER, colorBufferID);
	g.glBufferData(GL_ARRAY_BUFFER, sizeof(colors), &colors[0], GL_STATIC_DRAW);
	g.glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	g.glEnableVertexAttribArray(1);

	// Load Shaders
  loadShaders();
}

void ResaltatSeleccionat::postFrame() {
	GLWidget &g = *glwidget();
  g.makeCurrent();

	
	int seleccionat = scene()->selectedObject();
	if (seleccionat != -1) {
		program->bind();

	  GLint polygonMode;
	  g.glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
	  g.glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	  const Object& object = scene()->objects()[seleccionat];

	  // Draw Boxes
	  QMatrix4x4 MVP=camera()->projectionMatrix()*camera()->viewMatrix();
	  program->setUniformValue("modelViewProjectionMatrix", MVP);

		program->setUniformValue("boundingBoxMin", object.boundingBox().min());
		program->setUniformValue("boundingBoxMax", object.boundingBox().max());

		g.glBindVertexArray(VAO);
		g.glDrawArrays(GL_TRIANGLE_STRIP, 0, 18);
		g.glBindVertexArray(0);

		g.glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
		program->release();
	}
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(bounding-box, BoundingBox)   // plugin name, plugin class
#endif
