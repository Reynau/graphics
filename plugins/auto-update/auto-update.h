#ifndef _AUTO_UPDATE_H
#define _AUTO_UPDATE_H

#include "basicplugin.h"

class AutoUpdate : public QObject, public BasicPlugin
 {
     Q_OBJECT
     #if QT_VERSION >= 0x050000
       Q_PLUGIN_METADATA(IID "BasicPlugin")   
     #endif
     Q_INTERFACES(BasicPlugin)

 public:
    virtual void onPluginLoad();	    
 
 };
 
 #endif
 
 
