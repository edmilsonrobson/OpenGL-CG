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

// ----------------------------------------------------------
// Declara��es de Fun��es
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Vari�veis Globais
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;

// ----------------------------------------------------------
// fun��o display()
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

void display(){

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
   //glOrtho(-7.0,7.0,-5.0,5.0,-1.0,50.0);
  gluPerspective(60.0, 1.0, 0.5, 50.0);
 // glFrustum(-7.0, 7.0, -5.0, 5.0, -3.0, 3.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(10, 15, 30, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0);


// scale for the table 14, 0.5, 8


  // LEGS

  double legSizeX = 1;
  double legSizeY = 6;
  double legSizeZ = 1;

  glPushMatrix();  
  glTranslatef(-5.0, 0, 5.0);  
  glScalef(legSizeX, legSizeY, legSizeZ);
  glColor3f(0.8,0.8,0.8);
  cube::draw(1);
  glPopMatrix();

  glPushMatrix();  
  glTranslatef(5.0, 0, 5.0);  
  glScalef(legSizeX, legSizeY, legSizeZ);
  glColor3f(0.8,0.8,0.8);
  cube::draw(1);
  glPopMatrix();

  glPushMatrix();  
  glTranslatef(-5.0, 0, -5.0);  
  glScalef(legSizeX, legSizeY, legSizeZ);
  glColor3f(0.8,0.8,0.8);
  cube::draw(1);
  glPopMatrix();

  glPushMatrix();  
  glTranslatef(5.0, 0, -5.0);  
  glScalef(legSizeX, legSizeY, legSizeZ);
  glColor3f(0.8,0.8,0.8);
  cube::draw(1);
  glPopMatrix();

  glFlush();
}


// ----------------------------------------------------------
// Fun��o specialKeys()
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

  //  Seta direita - aumenta rota��o em 5 graus
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //  Seta para esquerda - diminui a rota��o por 5 graus
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  //  Requisitar atualiza��o do display
  glutPostRedisplay();

}

// ----------------------------------------------------------
// Fun��o main()
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Inicializa o GLUT e processa os par�metros do usu�rio GLUT
  glutInit(&argc,argv);

  //  Requisita uma janela com buffer duplo e true color com um Z-buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

  // Cria a janela do programa
  glutCreateWindow("Super Cube");

  //  Habilita o teste de profundidade do Z-buffer
  glEnable(GL_DEPTH_TEST);

  // Fun��es
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);

  //  Passa o controle dos eventos para o GLUT
  std::cout << "hello";
  glutMainLoop();

  //  Retorna para o SO
  
  return 0;

}
