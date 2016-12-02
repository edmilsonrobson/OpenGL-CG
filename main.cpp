#include <stdio.h>
#include <stdarg.h>
#include <iostream>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

double camx, camy, camz;

// ----------------------------------------------------------
// Declarações de Funções
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Variáveis Globais
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;

// ----------------------------------------------------------
// função display()
// ----------------------------------------------------------

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

void drawTable(double x, double y, double z){

  // LEGS

  double legSizeX = 1;
  double legSizeY = 6;
  double legSizeZ = 1;

  glPushMatrix();  
  glTranslatef(-13.0+x, 0+y, 7.5+z);  
  glScalef(legSizeX, legSizeY, legSizeZ);
  glColor3f(1, 1, 1);
  cube::draw(1);
  glPopMatrix();

  glPushMatrix();  
  glTranslatef(13.0+x, 0+y, 7.5+z);  
  glScalef(legSizeX, legSizeY, legSizeZ);
  glColor3f(1, 1, 1);
  cube::draw(1);
  glPopMatrix();

  glPushMatrix();  
  glTranslatef(-13.0+x, 0+y, -7.5+z);  
  glScalef(legSizeX, legSizeY, legSizeZ);
  glColor3f(1, 1, 1);
  cube::draw(1);
  glPopMatrix();

  glPushMatrix();  
  glTranslatef(13.0+x, 0+y, -7.5+z);  
  glScalef(legSizeX, legSizeY, legSizeZ);
  glColor3f(1, 1, 1);
  cube::draw(1);
  glPopMatrix();

  // TAMPÃO DA MESA
  glPushMatrix();  
  glTranslatef(0+x, 6.5+y, 0+z);  
  glScalef(14, 0.5, 8);
  glColor3f(0.5,0,0);
  cube::draw(1);
  glPopMatrix();

  // CPU
  glPushMatrix();  
  glTranslatef(-10+x, 11+y, -4+z);  
  glScalef(1, 4, 5);
  glColor3f(1,1,1);
  cube::draw(1);
  glPopMatrix();

  // MONITOR
  // base
  glPushMatrix();  
  glTranslatef(0+x, 7.25+y, -4+z);  
  glScalef(4, 0.2, 3);
  glColor3f(1,1,1);
  cube::draw(1);
  glPopMatrix();

  // neck
  glPushMatrix();  
  glTranslatef(0+x, 11+y, -5+z);  
  glScalef(1, 4, 1);
  glColor3f(0.5,0.5,0.5);
  cube::draw(1);
  glPopMatrix();

  // monitor
  glPushMatrix();  
  glTranslatef(0+x, 13+y, -3+z);  
  glScalef(5, 3.5, 1);
  glColor3f(1,0,0);
  cube::draw(1);
  glPopMatrix();

  // base
  glPushMatrix();  
  glTranslatef(0+x, 7.25+y, 4+z);  
  glScalef(6, 0.2, 2);
  glColor3f(1,1,1);
  cube::draw(1);
  glPopMatrix();

}

void display(){

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //glOrtho(-7.0,7.0,-5.0,5.0,-1.0,50.0);
  gluPerspective(60.0, 1.0, 0.5, 50.0);
  glFrustum(0, 0, 0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(camx, camy, camz, 0, 0, 0-10, 0.0, 1.0, 0.0);


// scale for the table 14, 0.5, 8


  
  glPushMatrix();  
  glTranslatef(0,-6,0);
  glScalef(100, 0.1, 100);
  glColor3f(0, 1, 0);
  cube::draw(1);
  glPopMatrix();

  drawTable(0,0,0);
  drawTable(5,0,-18);
  


  glFlush();
}


// ----------------------------------------------------------
// Função specialKeys()
// ----------------------------------------------------------
void specialKeys(unsigned char key, int x, int y ) {

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

  //  Requisitar atualização do display
  glutPostRedisplay();

}

// ----------------------------------------------------------
// Função main()
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Inicializa o GLUT e processa os parâmetros do usuário GLUT
  glutInit(&argc,argv);

  camx = 0;
  camy = 0;
  camz = 30;

  //  Requisita uma janela com buffer duplo e true color com um Z-buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

  // Cria a janela do programa
  glutCreateWindow("LEC 2");
  glClearColor(0.7,0.8,1, 1);
  //  Habilita o teste de profundidade do Z-buffer
  glEnable(GL_DEPTH_TEST);

  // Funções
  glutDisplayFunc(display);
  glutKeyboardFunc(specialKeys);

  //  Passa o controle dos eventos para o GLUT
  std::cout << "hello";
  glutMainLoop();

  //  Retorna para o SO
  
  return 0;

}
