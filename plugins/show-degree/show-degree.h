#ifndef _SHOWDEGREE_H
#define _SHOWDEGREE_H

#include "basicplugin.h"
#include <QElapsedTimer>

class ShowDegree : public QObject, public BasicPlugin {
  Q_OBJECT
  #if QT_VERSION >= 0x050000
     Q_PLUGIN_METADATA(IID "BasicPlugin")   
#endif
  Q_INTERFACES(BasicPlugin)

private:
  float grau;

  GLuint textureID;
  QOpenGLShaderProgram* program;
  QOpenGLShader *vs, *fs;

public:
  void onPluginLoad();
  void postFrame();
  void updateFPS();
};

#endif
