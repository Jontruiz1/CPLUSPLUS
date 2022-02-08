/*
	Little Flight Simulator using OpenGL
	Control ship with keyboard
	J and L will roll the plane
	I and K will pitch the plane
	H and ; will yaw the plane
	8 will increase speed, M will decrease speed
	W will toggle wireframe mode
	R will generate new landscape
*/
#include <gl\glut.h>
#include <iostream>
#include "Cockpit.h"
#include "Landscape.h"


Landscape landscape(200, 143);
static bool wireframe = false;
static Ship theShip(Point(60, 40, 220));
static Cockpit cockpit(theShip);
const double deltaSpeed = 0.01;
const double angle = 0.02;

void newLandScape() {
	static double rug = ((double)rand()) / RAND_MAX;
	landscape.create(rug);

}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	wireframe ? landscape.drawWireFrame() : landscape.draw();
	cockpit.draw();
	glFlush();
	glutSwapBuffers();
}
void Init() {
	srand(time(NULL));
	glEnable(GL_DEPTH_TEST);
	newLandscape();
	cockpit.create();
	GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat dark[] = { 0.2, 0.15, 0.2, 1.0 };
	GLfloat direction[] = { 0.2, 1.0, 0.5, 0.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, white);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);

	glLightfv(GL_LIGHT0, GL_AMBIENT, dark);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_AMBIENT, direction);

	glEnable(GL_LIGHT0);

}

// use timer if 3d movement and stuff like that 
void Timer(int v) {

	theShip.fly();
	Point eye(theShip.getPosition());
	Point at(theShip.getPosition() + theShip.getDirection());
	Vector up(theShip.getVertical());
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, at.x, at.y, at.z, up.i, up.j, up.k);
	glutPostRedisplay();
	glutTimerFunc(1000/60, Timer, v);
}


void Reshape(int width, int height) {

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)width / (GLfloat)height, 0.05, 300.0);
	glMatrixMode(GL_MODELVIEW);

}

void Keyboard(unsigned char key, int, int) {
	switch (key) {
	case 'j':
	case 'l':
	case 'i':
	case 'k':
	case 'h':
	case ';':
	case '8':
		theShip.setSpeed(theShip.getSpeed() + deltaSpeed);
		break;
	case'm':
		theShip.setSpeed(theShip.getSpeed() - deltaSpeed);
		break;
	case'W':
		wireframe = !wireframe;
		break;
	case'R':
		newLandScape();
		break;
	}
}

void writeHelpToConsole() {
	using std::endl;
	using std::cout;
	cout << "j/l -- role left and right" << endl;
	cout << "i/k -- pitch down and up" << endl;
	cout << "h/; -- yaw left and right" << endl;
	cout << "8/m -- speed up and slow down" << endl;
	cout << "W   -- toggle wireframe mode" << endl;
	cout << "R   -- generate new landscape" << endl;
}

int main(int argc, char** argv) {
	writeHelpToConsole();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 500);
	glutCreateWindow("Simple Flight Simulator");
	glutReshapeFunc(Reshape);
	glutTimerFunc(100, Timer, 0);
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Keyboard);
	Init();
	glutMainLoop();
}