#ifndef _RESALTATSELECCIONAT_H
#define _RESALTATSELECCIONAT_H

#include "basicplugin.h"

class ResaltatSeleccionat : public QObject, public BasicPlugin {
	Q_OBJECT
#if QT_VERSION >= 0x050000
	Q_PLUGIN_METADATA(IID "BasicPlugin")   
#endif
  Q_INTERFACES(BasicPlugin)

private:
	GLuint VAO;
	GLuint coordBufferID;
	GLuint colorBufferID;
	GLuint indexBufferID;

  QOpenGLShaderProgram* program;
  QOpenGLShader *vs, *fs;

  void loadShaders();

public:
  void onPluginLoad();
  void postFrame();
};

#endif
