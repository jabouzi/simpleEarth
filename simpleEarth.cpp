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

#include "simpleEarth.h"
#include "countries.h"
#include <math.h>

using namespace std;
using namespace qglviewer;

Viewer::~Viewer()
{
	glDeleteTextures(1, &texture);
}

// Draws a spiral
void Viewer::draw()
{
    //glBindTexture(GL_TEXTURE_2D, texture);
    //gluSphere(quadric, 5.0, 50, 100);
    float pos[4] = {1.0, 0.5, 7000.0, 0.0};
    // Directionnal light
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

    pos[3] = 7000.0;
    // Spot light
    light1->getPosition(pos[0], pos[1], pos[2]);
    glLightfv(GL_LIGHT1, GL_POSITION, pos);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1->inverseTransformOf(Vec(0,0,1)));

    // Point light
    light2->getPosition(pos[0], pos[1], pos[2]);
    glLightfv(GL_LIGHT2, GL_POSITION, pos);
    
    drawEarth();

    drawLight(GL_LIGHT0);

    if (light1->grabsMouse())
        drawLight(GL_LIGHT1, 1.2f);
    else
        drawLight(GL_LIGHT1);

    if (light2->grabsMouse())
        drawLight(GL_LIGHT2, 1.2f);
    else
        drawLight(GL_LIGHT2);

    //drawNames();
}

void Viewer::init()
{
    setSceneRadius(7000);
	showEntireScene();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Light0 is the default ambient light
    glEnable(GL_LIGHT0);

    // Light1 is a spot light
    glEnable(GL_LIGHT1);
    const GLfloat light_ambient[4]  = {0.8f, 0.2f, 0.2f, 1.0};
    const GLfloat light_diffuse[4]  = {1.0, 0.4f, 0.4f, 1.0};
    const GLfloat light_specular[4] = {1.0, 0.0, 0.0, 1.0};

    glLightf( GL_LIGHT1, GL_SPOT_EXPONENT,  3.0);
    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF,    20.0);
    glLightf( GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.5);
    glLightf( GL_LIGHT1, GL_LINEAR_ATTENUATION, 1.0);
    glLightf( GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 1.5);
    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);

    // Light2 is a classical directionnal light
    glEnable(GL_LIGHT2);
    const GLfloat light_ambient2[4]  = {0.2f, 0.2f, 2.0, 1.0};
    const GLfloat light_diffuse2[4]  = {0.8f, 0.8f, 1.0, 1.0};
    const GLfloat light_specular2[4] = {0.0, 0.0, 1.0, 1.0};

    glLightfv(GL_LIGHT2, GL_AMBIENT,  light_ambient2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  light_diffuse2);

    light1 = new ManipulatedFrame();
    light2 = new ManipulatedFrame();
    setMouseTracking(true);

    light1->setPosition(0.5, 0.5, 7000);
    // Align z axis with -position direction : look at scene center
    light1->setOrientation(Quaternion(Vec(0,0,1), -light1->position()));

    light2->setPosition(-0.5, 0.5, 7000);

    QImage image = QGLWidget::convertToGLFormat(QImage("earth.jpg"));
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	gluBuild2DMipmaps(GL_TEXTURE_2D,     // texture to specify
			  GL_RGBA,           // internal texture storage format
			  image.width(),     // texture width
			  image.height(),    // texture height
			  GL_RGBA,           // pixel format
			  GL_UNSIGNED_BYTE,  // color component format
			  image.bits());     // pointer to texture image

    for (int x=0; x<=EARTH_LON_RES; x++) {
        for (int y=0; y<=EARTH_LAT_RES; y++) {
            // angle around y-axis (which is x-value)
            float    angX, angY;
            angX = (x * 360.f / EARTH_LON_RES) * PI / 180.f;
            angY = (-90.f + (y * 180.f / EARTH_LAT_RES)) * PI / 180.f;
            vertices[x][y].x = fabsf(cosf(angY)) * EARTH_RADIUS * sinf(angX);
            vertices[x][y].y = EARTH_RADIUS * sinf(angY);
            vertices[x][y].z = fabsf(cosf(angY)) * EARTH_RADIUS * cosf(angX);
            mapping[x][y].u = (float)x / EARTH_LON_RES;
            mapping[x][y].v = (float)y / EARTH_LAT_RES;
        }
    }
}

void Viewer::drawEarth()
{
    glEnable(GL_LIGHTING);
        
    /*GLfloat matAmbient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat matShininess[] = { 10.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);*/

    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, texture);
    //glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    //glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    int x, y;  
    for (y=0; y<EARTH_LAT_RES; y++) {
        //glBegin(GL_QUAD_STRIP);  
        glBegin(GL_POINTS);  
        for (x=0; x<EARTH_LON_RES; x++) {
            glTexCoord2fv((GLfloat*)&mapping[x][y]);
            glVertex3fv((GLfloat*)&vertices[x][y]);
            glTexCoord2fv((GLfloat*)&mapping[x][y+1]);
            glVertex3fv((GLfloat*)&vertices[x][y+1]);
            glTexCoord2fv((GLfloat*)&mapping[x+1][y]);
            glVertex3fv((GLfloat*)&vertices[x+1][y]);
            glTexCoord2fv((GLfloat*)&mapping[x+1][y+1]);
            glVertex3fv((GLfloat*)&vertices[x+1][y+1]);
        }
        glEnd();
    }
    //glDisable(GL_TEXTURE_2D);
    
    /*GLfloat lightKa[] = {.5f, .5f, .5f, 1.0f};      // ambient light
    GLfloat lightKd[] = {.9f, .9f, .9f, 1.0f};      // diffuse light
    GLfloat lightKs[] = {1, 1, 1, 1};               // specular light
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

    // position the light
    float lightPos[4] = {0, 0, 7000, 0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);*/

    //glEnable(GL_LIGHT0);   
}

void Viewer::drawNames()
{
    glLineWidth(1);
    Vector countries_positions[NUM_COUNTRIES];
    Vector countries_positions2[NUM_COUNTRIES];
    QFont myFont( "TypeWriter", 6, QFont::Bold);
    for (int i=0; i<NUM_COUNTRIES-1; i++) {
       lonLat2Point(countries[i].lon, countries[i].lat, &countries_positions[i],0);
       lonLat2Point(countries[i].lon, countries[i].lat, &countries_positions2[i],1000);
       glBegin(GL_LINES);
           glColor4f(1,0,0,1.0f);
           glVertex3f (countries_positions[i].x  ,  countries_positions[i].y  ,  countries_positions[i].z);
           glVertex3f (countries_positions2[i].x  ,  countries_positions2[i].y  ,  countries_positions2[i].z);
       glEnd();
       glColor4f(1.0, 1.0, 1.0, 1.0);
       renderText(countries_positions2[i].x  ,  countries_positions2[i].y  ,  countries_positions2[i].z, QString(countries[i].name), myFont );
    }
}

void Viewer::lonLat2Point(float lon, float lat, Vector *pos, int extra = 0)
{
    // lat -90..90 => Y
    // lon -180..180 => X
    float    angX, angY;
    angX = (180.f+lat) * PI / 180.f;
    angY = lon * PI / 180.f;
    pos->x = fabsf(cosf(angY)) * (EARTH_RADIUS + extra) * sinf(angX);
    pos->y = EARTH_RADIUS * sinf(angY);
    pos->z = fabsf(cosf(angY)) * (EARTH_RADIUS + extra) * cosf(angX);
}

QString Viewer::helpString() const
{
  QString text("<h2>S i m p l e V i e w e r</h2>");
  text += "Use the mouse to move the camera around the object. ";
  text += "You can respectively revolve around, zoom and translate with the three mouse buttons. ";
  text += "Left and middle buttons pressed together rotate around the camera view direction axis<br><br>";
  text += "Pressing <b>Alt</b> and one of the function keys (<b>F1</b>..<b>F12</b>) defines a camera keyFrame. ";
  text += "Simply press the function key again to restore it. Several keyFrames define a ";
  text += "camera path. Paths are saved when you quit the application and restored at next start.<br><br>";
  text += "Press <b>F</b> to display the frame rate, <b>A</b> for the world axis, ";
  text += "<b>Alt+Return</b> for full screen mode and <b>Control+S</b> to save a snapshot. ";
  text += "See the <b>Keyboard</b> tab in this window for a complete shortcut list.<br><br>";
  text += "Double clicks automates single click actions: A left button double click aligns the closer axis with the camera (if close enough). ";
  text += "A middle button double click fits the zoom of the camera and the right button re-centers the scene.<br><br>";
  text += "A left button double click while holding right button pressed defines the camera <i>Revolve Around Point</i>. ";
  text += "See the <b>Mouse</b> tab and the documentation web pages for details.<br><br>";
  text += "Press <b>Escape</b> to exit the viewer.";
  return text;
}
