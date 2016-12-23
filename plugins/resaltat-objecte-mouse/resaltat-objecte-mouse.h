 #ifndef _RESALTAT_OBJECTE_MOUSE_H  
#define _RESALTAT_OBJECTE_MOUSE_H

#include "basicplugin.h"

class ResaltatObjecteMouse : public QObject, public BasicPlugin {

  Q_OBJECT
#if QT_VERSION >= 0x050000
  Q_PLUGIN_METADATA(IID "BasicPlugin")   
#endif
  Q_INTERFACES(BasicPlugin)

  void drawDrawColorScene();

  void setSelectedObject(int selected);

  GLuint textureID;
  QOpenGLShaderProgram* programColor;
  QOpenGLShader* vsColor;
  QOpenGLShader* fsColor;

public:
  void onPluginLoad();
  void mouseReleaseEvent(QMouseEvent* e);

};

#endif
