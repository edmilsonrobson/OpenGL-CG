#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <stdarg.h>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define GLfloat float
#define PI 3.1415926
static int camx,camy,camz;
using namespace std;
class roll
{
	public:
	static void drawRoll (float y1, float y2, float r)
	{
		for (float j = y1; j < y2;j+= 0.002)
		{
			glBegin(GL_POLYGON);
			for (int i = 0;i < 500;i++)
			{
			    float angulo = (float)(i*2.0*PI)/1000.0;
			    glVertex3f(r*std::cos(angulo),j,r*sin(angulo));
			}
			glEnd();
		}
        }
};
class cube
{
	public:
	static void draw (GLfloat L)
	{
		//FRONT
		glBegin(GL_QUADS);
		glVertex3f(  L, -L, -L );      // P1 is red
		glVertex3f(  L,  L, -L );      // P2 is green
		glVertex3f( -L,  L, -L );      // P3 is blue
		glVertex3f( -L, -L, -L );      // P4 is purple
		glEnd();
		//BACK
		glBegin(GL_QUADS);
		glVertex3f(  L, -L, L );
		glVertex3f(  L,  L, L );
		glVertex3f( -L,  L, L );
		glVertex3f( -L, -L, L );
		glEnd();
		//RIGHT
		glBegin(GL_QUADS);
		glVertex3f( L, -L, -L );
		glVertex3f( L,  L, -L );
		glVertex3f( L,  L,  L );
		glVertex3f( L, -L,  L );
		glEnd();
		//LEFT
		glBegin(GL_QUADS);
		glVertex3f( -L, -L,  L );
		glVertex3f( -L,  L,  L );
		glVertex3f( -L,  L, -L );
		glVertex3f( -L, -L, -L );
		glEnd();
		//TOP
		glBegin(GL_QUADS);
		glVertex3f(  L,  L,  L );
		glVertex3f(  L,  L, -L );
		glVertex3f( -L,  L, -L );
		glVertex3f( -L,  L,  L );
		glEnd();
		//BOTTOM
		glBegin(GL_QUADS);
		glVertex3f(  L, -L, -L );
		glVertex3f(  L, -L,  L );
		glVertex3f( -L, -L,  L );
		glVertex3f( -L, -L, -L );
		glEnd();
	}
};
class tower : cube
{
	public:
		static void drawTower(GLfloat posx, GLfloat posy, GLfloat posz, GLfloat scalex, GLfloat scaley, GLfloat scalez, GLfloat L)
		{
			glTranslatef(posx,posy,posz);
			glScalef(scalex,scaley,scalez);
			draw(L);
		}
};
class ramp : cube
{
	public:
		static void drawRamp(GLfloat posx, GLfloat posy, GLfloat posz, GLfloat scalex, GLfloat scaley, GLfloat scalez, GLfloat L, GLfloat angle)
		{
			glTranslatef(posx,posy,posz);
			glRotatef(90.0,0.0,1.0,0.0);
			glRotatef(angle,0.0,0.0,1.0);
			glScalef(scalex,scaley,scalez);
			draw(L);
		}
};
class Hemisphere
{
	public:
	static void drawHemisphere (int lat, int lon)
	{
		glBegin(GL_QUAD_STRIP);
		int halflat = lat/2;
		for (int i = 0;i <= halflat; i++)
		{
			double lat0 = PI*(-0.5 + (float) (i-1)/lon), z0 = sin(lat0), zr0 = std::cos(lat0);
			double lat1 = PI*(-0.5 + (float) (i)/lon), z1 = sin(lat1), zr1 = std::cos(lat1);
			for (int j = 0;j <= lon;j++)
			{
				double lng = 2.0*PI*((float) (j-1)/lon);
				glVertex3f(std::cos(lng)*zr0,sin(lng)*zr0,z0);
				glVertex3f(std::cos(lng)*zr1,sin(lng)*zr1,z1);
			}
		}
		glEnd();
	}
};
class congresso
{
public:
    static void keyboard(unsigned char key, int x, int y)
    {
	switch (key)
	{
		case 'd': 
			camx += 1.0;
			break;
		case 'a': 
			camx -= 1.0;
			break;
		case 'w': 
			camy += 1.0;
			break;
		case 's': 
			camy -= 1.0;
			break;
		case 'f':
			camz -= 1.0;
			break;
		case 'r':
			camz += 1.0;
			break;
		default: 
			break;
	}
	glutPostRedisplay();
    }
    static void myReshape (int w, int h)
    {
        glViewport(0,0,w,h);
    }
    static void myinit(void)
    {
       
	    }
    static void draw(void)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
         //glOrtho(-7.0,7.0,-5.0,5.0,-1.0,50.0);
        gluPerspective(60.0, 1.0, 0.5, 50.0);
       // glFrustum(-7.0, 7.0, -5.0, 5.0, -3.0, 3.0);
        glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(camx, camy, camz, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);
		//Left Hemisphere
		glPushMatrix();
		glTranslatef(-2.0,0.0,-8.0);
		glRotatef(90.0,1.0, 0.0, 0.0);
		glColor3f(0.8,0.8,0.8);
	        Hemisphere::drawHemisphere(20.0,20.0);
		glPopMatrix();

	glFlush();
    }

};
int main(int argc, char *argv[])
{
    camx = camy = camz = 0.0;
    glutInit(&argc, argv); //initialize glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("GLUT Congresso Nacional 3D");
    congresso::myinit();
    glutDisplayFunc(congresso::draw);
    glutKeyboardFunc(congresso::keyboard);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
