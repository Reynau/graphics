#ifndef _NAME_H
#define _NAME_H

#include "basicplugin.h"

class ClassName : public QObject, public BasicPlugin {
	Q_OBJECT
#if QT_VERSION >= 0x050000
	Q_PLUGIN_METADATA(IID "BasicPlugin")   
#endif
  Q_INTERFACES(BasicPlugin)

private:
  QOpenGLShaderProgram* program;
  QOpenGLShader *vs, *fs;

public:
  void onPluginLoad();
  void postFrame();
  void updateFPS();
};

#endif
