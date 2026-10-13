#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float alpx=0,alpy=0,alpz=0;

void DrawAxes(float l){
int i;
glLineWidth(2);
glBegin(GL_LINES);
//X tenhleg
glColor3f(1.0,0.0,0.0);
glVertex3f(-l,0.0,0.0);
glVertex3f(l,0.0,0.0);
//Y tenhleg
glColor3f(0.0,0.0,1.0);
glVertex3f(0.0,-l,0.0);
glVertex3f(0.0,l,0.0);
//Z tenhleg
glColor3f(0.0,1.0,0.0);
glVertex3f(0.0,0.0,-l);
glVertex3f(0.0,0.0,l);
glEnd();
glPointSize(5);
glBegin(GL_POINTS);
glColor3f(1.0,0.0,0.0);
glVertex3f(l,0.0,0.0);//X-iin uzuur
glColor3f(0.0,0.0,1.0);
glVertex3f(0.0,l,0.0);//Y-iin uzuur
glColor3f(0.0,1.0,0.0);
glVertex3f(0.0,0.0,l);//Z-iin uzuur
glEnd();
//huwaariin shugamuud
glColor3f(0.7,0.7,0.7);
glLineWidth(1);
for(i=-l;i<=l;i++)
{
glBegin(GL_LINES);
glVertex3f(-l,i,0.0);
glVertex3f(l,i,0.0);
glEnd();
        }
for(i=-l;i<=l;i++)
{
glBegin(GL_LINES);
glVertex3f(i,-l,0.0);
glVertex3f(i,l,0.0);
glEnd();
        }
}

void draw()
{
glPushMatrix();
glRotatef(alpx,1,0,0);
glRotatef(alpy,0,1,0);
glRotatef(alpz,0,0,1);

//??????????? ??????? ?????.
DrawAxes(10);
//??? ?????? ???? ?????? ?????.

glPopMatrix();
}
void render()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  draw();
  glutSwapBuffers();
}
void keypress(unsigned char c, int a, int b)
{
  if ( c==27 ) exit(0);
  else
  if ( c=='X' ) alpx+=5;
  else
  if ( c=='x' ) alpx-=5;
  else
  if ( c=='Y' ) alpy+=5;
  else
  if ( c=='y' ) alpy-=5;
  else
  if ( c=='Z' ) alpz+=5;
  else
  if ( c=='z' ) alpz-=5;
  glutPostRedisplay();
}
void resize(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10.0, 10.0,-10.0,10.0,-10.0, 10.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
int main(int argc, char * argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("3 hemjeest ogtorgui");
  glutReshapeFunc(resize);
  glutReshapeWindow(500,500);
  glutKeyboardFunc(keypress);
  glutDisplayFunc(render);
  glutMainLoop();
  return 0;
} 
