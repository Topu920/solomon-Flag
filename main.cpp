#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
 float Pi = 3.1415926535897932384626433832795;
void DrawStar(float fX, float fY) {
	const float Radius = 0.04;
	const float InnerRadius = Radius*(1.0/(sin((2.0*Pi)/5.0)*2.0*cos(Pi/10.0) + sin((3.0*Pi)/10.0)));
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(fX, fY, 0.0);
		for (int i = 0; i < 10; ++i) {
			float fAngleStart	= Pi/2.0 + (i*2.0*Pi)/10.0;
			float fAngleEnd		= fAngleStart + Pi/5.0;
			if (i % 2 == 0) {
				glVertex3f((fX + Radius*cos(fAngleStart)/1.9), (fY + Radius*sin(fAngleStart)), 0.0);
				glVertex3f((fX + InnerRadius*cos(fAngleEnd)/1.9), (fY + InnerRadius*sin(fAngleEnd)), 0.0);
			} else {
				glVertex3f((fX + InnerRadius*cos(fAngleStart)/1.9), (fY + InnerRadius*sin(fAngleStart)), 0.0);
				glVertex3f((fX + Radius*cos(fAngleEnd)/1.9), (fY + Radius*sin(fAngleEnd)), 0.0);
			}
		}
	glEnd();
}

void quad()
{
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.0);///red
        glVertex3f(.65,.8,0.0);
		glVertex3f(.8,.8,0.0);
		glVertex3f(.35,.2,0.0);
		glVertex3f(.2,.2,0.0);
		glEnd();

}
void triangle()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.0);///green
    glVertex3f(.22,.2,0.0);
    glVertex3f(.8,.8,0.0);
    glVertex3f(.8,.2,0.0);

     glColor3f(0.0,0.0,0.8);///Blue
    glVertex3f(.2,.2,0.0);
    glVertex3f(.2,.8,0.0);
    glVertex3f(.78,.8,0.0);

    glEnd();

}

void Draw() {
	 glClear(GL_COLOR_BUFFER_BIT);
     quad();
     triangle();
     DrawStar(.235,.7);
     DrawStar(.33,.7);
     DrawStar(.283,.64);
     DrawStar(.235,.58);
     DrawStar(.33,.58);


	glFlush();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(950, 500);///black windows er length and wide
	glutInitWindowPosition(200, 200);
	glutCreateWindow("XoaX.net");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
