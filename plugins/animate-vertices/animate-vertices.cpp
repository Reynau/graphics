#include "animate-vertices.h"
#include "glwidget.h"
#include "camera.h"
#include <QTimer>

using namespace std;

void AnimateVertices::onPluginLoad () {
  vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
  vs->compileSourceFile("/home/xavi/Documents/University/G/shaders/14.AnimateVertices1/animate-vertices-1.vert");
  
  fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
  fs->compileSourceFile("/home/xavi/Documents/University/G/shaders/14.AnimateVertices1/animate-vertices-1.frag");
  
  program = new QOpenGLShaderProgram(this);
  program->addShader(vs);
  program->addShader(fs);
  program->link();
  
  elapsedTimer.start();
  
  // Automatic refresh
  QTimer* timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), glwidget(), SLOT(update()));
  timer->start();
}

void AnimateVertices::preFrame () {
  program->bind();
  program->setUniformValue("time", float(elapsedTimer.elapsed()/1000.0f));
  QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
  program->setUniformValue("modelViewProjectionMatrix", MVP);
  QMatrix3x3 NM = camera()->viewMatrix().normalMatrix();
  program->setUniformValue("normalMatrix", NM);
}

void AnimateVertices::postFrame () {
  program->release();
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(animate-vertices, AnimateVertices)   // plugin name, plugin class
#endif
