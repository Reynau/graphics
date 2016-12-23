#include "seleccio-obj-teclat.h"
#include "glwidget.h"
using namespace std;

void SeleccioTeclat::setSelectedObj(int id) {
  if (id < 0 || id >= (int) scene()->objects().size())
    scene()->setSelectedObject(-1);
  else scene()->setSelectedObject(id);
  glwidget()->update();
}

void SeleccioTeclat::keyPressEvent (QKeyEvent* e) {
  if (e->key() >= 48 && e->key() <= 57)
    setSelectedObj(e->key() - 48);
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(NAME, ClassName)   // plugin name, plugin class
#endif
