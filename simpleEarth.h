/****************************************************************************

 Copyright (C) 2002-2011 Gilles Debunne. All rights reserved.

 This file is part of the QGLViewer library version 2.3.10.

 http://www.libqglviewer.com - contact@libqglviewer.com

 This file may be used under the terms of the GNU General Public License 
 versions 2.0 or 3.0 as published by the Free Software Foundation and
 appearing in the LICENSE file included in the packaging of this file.
 In addition, as a special exception, Gilles Debunne gives you certain 
 additional rights, described in the file GPL_EXCEPTION in this package.

 libQGLViewer uses dual licensing. Commercial/proprietary software must
 purchase a libQGLViewer Commercial License.

 This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#include <QGLViewer/qglviewer.h>
#include <QGLWidget>

//#define WINDOW_WIDTH  500
//#define WINDOW_HEIGHT 500
#define PI 3.14159265
#define EARTH_LON_RES    60    // Longitude Resolution (x)
#define EARTH_LAT_RES    60    // Latitude Resolution (y)
#define EARTH_RADIUS    6378    // in kilometers
//#define EARTH_RADIUS2   6878    // in kilometers
//#define WORLD_SCALE        0.01f    // scale of all the world
//#define MIN_SCALE        0.5f    // how much can we zoom out
//#define MAX_SCALE        1.9f    // and in

struct Vector {
    float x, y, z;
};

struct Mapping {
    float u, v;
};

class Viewer : public QGLViewer
{
public:
	virtual ~Viewer();
protected :
  virtual void draw();
  virtual void init();  
  virtual QString helpString() const;
private:
	GLuint		texture;
	GLUquadric	*quadric;
    Vector vertices[EARTH_LON_RES+1][EARTH_LAT_RES+1];
    Mapping mapping[EARTH_LON_RES+1][EARTH_LAT_RES+1];
    void drawEarth();
    void drawNames();
    void lonLat2Point(float , float , Vector *, int);

    qglviewer::ManipulatedFrame* light1;
    qglviewer::ManipulatedFrame* light2;
};
