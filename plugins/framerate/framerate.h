#ifndef _FRAMERATE_H
#define _FRAMERATE_H

#include "basicplugin.h"
#include <QElapsedTimer>

class Framerate : public QObject, public BasicPlugin {
  Q_OBJECT
  #if QT_VERSION >= 0x050000
     Q_PLUGIN_METADATA(IID "BasicPlugin")   
#endif
  Q_INTERFACES(BasicPlugin)

private:
  int frameCount;
  int fps;

  GLuint textureID;
  QOpenGLShaderProgram* program;
  QOpenGLShader *vs, *fs;

public:
  void onPluginLoad();
  void postFrame();
  void updateFPS();
};

#endif
