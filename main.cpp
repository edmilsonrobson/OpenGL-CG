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

double camx, camy, camz, lookx, looky;

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



    GLfloat d1[] = { 0.2, 0.5, 0.8, 1.0 };
    GLfloat d2[] = { 0.3, 0.5, 0.6, 1.0 };
    GLfloat d3[] = { 0.4, 0.2, 0.2, 1.0 };

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

void lightning(){
  GLfloat luzAmbiente[4]={0.3,0.3,0.3,1.0}; 
  GLfloat luzDifusa[4]={1,1,1,1};
  GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
  GLfloat posicaoLuz[4]={40.0, 50.0, -20.0, 1.0};

  // Capacidade de brilho do material
  GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
  GLint especMaterial = 60;

  // Especifica que a cor de fundo da janela será preta
  glClearColor(0.0,0.8,1.0,0.0);
  
  // Habilita o modelo de colorização de Gouraud
  glShadeModel(GL_SMOOTH);

  // Define a refletância do material 
  glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
  // Define a concentração do brilho
  glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

  // Ativa o uso da luz ambiente 
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

  // Define os parâmetros da luz de número 0
  glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
  glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
  glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

  // Habilita a definição da cor do material a partir da cor corrente
  glEnable(GL_COLOR_MATERIAL);
  //Habilita o uso de iluminação
  glEnable(GL_LIGHTING);  
  // Habilita a luz de número 0
  glEnable(GL_LIGHT0);

}

void drawLousa(double x, double y, double z){
    glPushMatrix();  
    glTranslatef(x, y, z);
    glScalef(50, 15, 0.2);
    glColor3f(1, 1, 1);
    cube::draw(1);
    glPopMatrix();
}

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
  //gluPerspective(60.0, 1.0, 0.5, 50.0);
  glFrustum(-2.58, 2.58, -1.5, 1.5, 3.0, 600.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(camx, camy, camz, camx, camy, camz-10, 0.0, 1.0, 0.0);


// scale for the table 14, 0.5, 8


  
  glPushMatrix();  
  glTranslatef(0,-6,0);
  glScalef(100, 0.1, 100);
  glColor3f(1, 1, 1);
  cube::draw(1);
  glPopMatrix();

  drawTable(-30,0,0);
  drawTable(-30,0,30);
  drawTable(-30,0,60);

  drawTable(30,0,0);
  drawTable(30,0,30);
  drawTable(30,0,60);

  drawLousa(20, 30, -90);
    
  //glutSolidSphere (6.0, 20, 16);


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
      camz += 1.0;
      break;
    case 'r':
      camz -= 1.0;
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
  lookx = 0;
  looky = 0;

  //  Requisita uma janela com buffer duplo e true color com um Z-buffer
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);


  // Cria a janela do programa
  glutCreateWindow("LEC 2");
  glClearColor(0.7,0.8,1, 1);
  glutReshapeWindow(1024,768);


lightning();
  
  // Funções
  glutDisplayFunc(display);

  glutKeyboardFunc(specialKeys);

  glEnable(GL_DEPTH_TEST);
  


  /*

    //  Habilita o teste de profundidade do Z-buffer
  

  

   //GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   //GLfloat mat_shininess[] = { 50.0 };
   GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0};   

   GLfloat light_ambient[] = { 0, 0, 0, 0};
   //glShadeModel (GL_SMOOTH);

   //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   //glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    glEnable (GL_COLOR_MATERIAL);
    //glColorMaterial (GL_FRONT, GL_DIFFUSE);
    glColorMaterial (GL_FRONT, GL_SPECULAR);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
   
*/


  //  Passa o controle dos eventos para o GLUT
  std::cout << "hello";
  glutMainLoop();

  //  Retorna para o SO
  
  return 0;

}
