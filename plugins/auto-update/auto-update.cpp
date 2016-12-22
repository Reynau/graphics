#include "auto-update.h"
#include "glwidget.h"

void AutoUpdate::onPluginLoad()
{
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), glwidget(), SLOT(update()));
	timer->start();
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(auto-update, AutoUpdate)   // plugin name, plugin class
#endif
