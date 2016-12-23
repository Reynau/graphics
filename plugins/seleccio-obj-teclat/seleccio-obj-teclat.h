#ifndef _SELECCIO_TECLAT_H
#define _SELECCIO_TECLAT_H

#include "basicplugin.h"

class SeleccioTeclat : public QObject, public BasicPlugin {
	Q_OBJECT
#if QT_VERSION >= 0x050000
	Q_PLUGIN_METADATA(IID "BasicPlugin")   
#endif
  Q_INTERFACES(BasicPlugin)

public:
  void keyPressEvent(QKeyEvent* e);
  void setSelectedObj(int id);
};

#endif
