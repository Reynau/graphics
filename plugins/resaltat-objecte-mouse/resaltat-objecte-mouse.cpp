#define GL_GLEXT_PROTOTYPES
#include "resaltat-objecte-mouse.h"
#include "glwidget.h"

void ResaltatObjecteMouse::setSelectedObject(int selected) {
  if (selected<0 || selected>=(int)scene()->objects().size()) selected=-1;
  scene()->setSelectedObject(selected);
}

void encodeID(int index, GLubyte *color) {
  color[0]=color[1]=color[2]=index;
}

// maxim 255 objectes. com que el valor de cada color va entre 0 i 255:
// 0-254 id objecte
// 255 cap objecte (el color de fons es blanc)
int decodeID(GLubyte color) {
  if (color==255) return -1;
  return color;
}

void ResaltatObjecteMouse::mouseReleaseEvent(QMouseEvent* e) {
  glwidget()->makeCurrent();
  if (!(e->button()&Qt::LeftButton)) return;          // boto esquerre del ratoli
  if (e->modifiers()&(Qt::ShiftModifier)) return;     // res de tenir shift pulsat
  if (!(e->modifiers()&Qt::ControlModifier)) return;  // la tecla control ha d'estar pulsada
  glClearColor(1, 1, 1, 1);                           // esborrar els buffers amb un color de fons únic (blanc)
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
std::cout << "drawing" << std::endl;
  programColor->bind();                               // activar (bind) el shader program amb el VS+FS d’abans
  drawDrawColorScene();
  programColor->release();
std::cout << "drawed" << std::endl;
  int x=e->x();                                       // llegir el color del buffer de color sota la posició del cursor
  int y=glwidget()->height()-e->y();
  GLubyte read[4];
  glReadPixels(x, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, read);
  int seleccio=decodeID(read[0]);                    // obtenir l'identificador de l'objecte corresponent i, 
cout <<   seleccio << endl;
  setSelectedObject(seleccio);                        // si no és color de fons, establir l'objecte seleccionat
  glwidget()->update();                             // cridar a updateGL per tal que es repinti l'escena
}

void ResaltatObjecteMouse::onPluginLoad() {
  glwidget()->makeCurrent();
  // Carregar shader, compile & link (escena colors unics)
  vsColor=new QOpenGLShader(QOpenGLShader::Vertex, this);
  vsColor->compileSourceFile("/home/xavi/Documents/University/G/viewer/plugins/resaltat-objecte-mouse/resaltat-objecte-mouse.vert");
  cout << "Log: " << vsColor->log().toStdString() << endl;
  fsColor=new QOpenGLShader(QOpenGLShader::Fragment, this);
  fsColor->compileSourceFile("/home/xavi/Documents/University/G/viewer/plugins/resaltat-objecte-mouse/resaltat-objecte-mouse.frag");
  cout << "Log: " << fsColor->log().toStdString() << endl;
  programColor=new QOpenGLShaderProgram(this);
  programColor->addShader(vsColor);
  programColor->addShader(fsColor);
  programColor->link();
  if (!programColor->isLinked()) cout << "Link error" << endl;
}

// Pintar l'escena assegurant-se que cada objecte es pinta amb un color únic 
// que permeti identificar l'objecte (i diferent del color de fons)
void ResaltatObjecteMouse::drawDrawColorScene() {
  // enviar la modelViewProjectionMatrix, i el color identificador dels objectes
  QMatrix4x4 MVP=camera()->projectionMatrix()*camera()->viewMatrix();
  programColor->setUniformValue("modelViewProjectionMatrix", MVP);
  for (unsigned int i=0; i<scene()->objects().size(); ++i) {
    GLubyte color[4];
    encodeID(i, color);
    programColor->setUniformValue("color", QVector4D(color[0]/255.0, color[1]/255., color[2]/255., 1.0));
cout << 4 << endl;
    if (drawPlugin()) 
  drawPlugin()->drawObject(i);
cout << 5 << endl;
  }

}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(resaltat-objecte-mouse, ResaltatObjecteMouse)   // plugin name, plugin class
#endif 
