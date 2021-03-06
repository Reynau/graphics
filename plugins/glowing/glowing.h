#ifndef _GLOWING_H
#define _GLOWING_H

#include "basicplugin.h"
#include <QGLShader>
#include <QGLShaderProgram>


class Glowing : public QObject, public BasicPlugin
 {
     Q_OBJECT
 #if QT_VERSION >= 0x050000
     Q_PLUGIN_METADATA(IID "BasicPlugin")   
#endif
     Q_INTERFACES(BasicPlugin)

 public:
    void onPluginLoad();
    bool paintGL();
 
 private:
    QGLShaderProgram* program;
    QGLShader* vs;
    QGLShader* fs;  
    GLuint textureId;
 };
 
 #endif
