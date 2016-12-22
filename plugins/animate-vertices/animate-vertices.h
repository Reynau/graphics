#ifndef _ANIMATEVERTICES_H
#define _ANIMATEVERTICES_H

#include "basicplugin.h"
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QTime>

class AnimateVertices : public QObject, public BasicPlugin {
  Q_OBJECT
  #if QT_VERSION >= 0x050000
     Q_PLUGIN_METADATA(IID "BasicPlugin")   
#endif
  Q_INTERFACES(BasicPlugin)

private:
  QOpenGLShaderProgram* program;
  QOpenGLShader *vs, *fs;
  QTime elapsedTimer;
  
public:
  void onPluginLoad();
  void preFrame();
  void postFrame();
};

#endif
