#pragma once
#if !defined COCKPIT_H
#define COCKPIT_H

#include <gl\glut.h>
#include "Ship.h"
#include <cmath>

class Cockpit {
public:
	Cockpit(Ship ship) : ship(ship) {};
	void create();
	void draw();
private:
	Ship ship;
	int cockpitID;
};


void Cockpit::create() {
	cockpitID = glGenLists(1);
	glNewList(cockpitID, GL_COMPILE);
	glDisable(GL_LIGHTING);
	glColor3f(.8, .8, .7);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, -1, 0);
	glVertex3f(1, -1, 0);
	for (double x = 1.0; x >= -1.05; x -= 0.05) {
		glVertex3f(x, 20*cos(x / 10.0) - 20.6, 0);
	}
	glVertex3f(-1, -1, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glEndList();
}
void Cockpit::draw() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glCallList(cockpitID);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

#endif