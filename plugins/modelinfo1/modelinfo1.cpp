#include "modelinfo1.h"
#include "glwidget.h"

using namespace std;

void ModelInfo::postFrame() {
  const vector<Object>& objects = scene()->objects();
  int numObjects = objects.size();
  int numPolygons = 0;
  int numVertexs = 0;
  int numTriangles = 0;
  for (int i = 0; i < numObjects; ++i) {
    const vector<Face>& faces = objects[i].faces();
    numPolygons += faces.size();
    numVertexs += objects[i].vertices().size();
    for (int j = 0; j < faces.size(); ++j) {
      if (faces[j].numVertices() == 3)
        ++numTriangles;
    }
  }
  cout << "numObjects: " << numObjects << endl;
  cout << "numPolygons: " << numPolygons << endl;
  cout << "numVertexs: " << numVertexs << endl;
  cout << "numTriangles: " << numTriangles << endl;
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(modelinfo1, ModelInfo)   // plugin name, plugin class
#endif
