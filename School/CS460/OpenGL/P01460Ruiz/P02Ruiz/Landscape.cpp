#include <iostream>
#include <vector>
#include "Landscape.h"

using namespace std;

vector<vector<double>> d;
/*
void Landscape::create(double rug) {
	int r, c;

	for (r = 0; r < rows; r++) {
		d[r][0] = d[r][columns - 1] = 0;
	}


}
*/

void Landscape::createSolidDisplayList() {
	//Drawing a solid landscape is fairly simple using GL_TRIANGLE_STRIP
	glNewList(solidID, GL_COMPILE);
	glEnable(GL_LIGHTING);
	glBegin(GL_QUAD);
	glVertex3f(-200, 0, 0, columns + 200);
	glVertex3f(-200, 0, -200);
	glVertex3f(rows + 200, 0, -200);
	glVertex3f(rows + 200, 0, columns + 200);
	glEnd();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; j++) {
			drawTriangle(i, j, i + 1, j, i, j + 1);
			drawTriangle(i+1, j, i+1, j+1, i, j+1)
		}
	}
	glEnd();
	glEndList();


}
void Landscape::createWireframeDisplayList() {
	//Straightforward but tedious
	glNewList(wireFrameID, GL_COMPILE);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	int x, z;

	for (x = 0; x < rows; ++x) {
		glBegin(GL_LINE_STRIP);
		glVertex3f(x, d[x][0], 0);
		for (z = 1; z < columns; ++z) {
			glVertex3f(x, d[x][z], z);
		}
		glEnd();
	}

	for (z = 0; z < columns; ++z) {
		glBegin(GL_LINE_STRIP);
		glVertex3f(0, d[0][z], z);
		for (x = 0; x < rows; ++x) {
			glVertex3f(z, d[x][z], z);
		}
		glEnd();
	}

}

//ensures every element in elevation grid is equal to unused
Landscape::Landscape(int r, int c) : rows(r), columns(c) {
	vector<double> nullRow(columns, unused); 
	vector<vector<double>> nullMatrix(rows, nullRow);
	d = nullMatrix;
}

void Landscape::drawTriangle(int x1, int z1, int x2, int z2, int x3, int z3) {


	highest = 0.0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (d[i][j] < 0) d[i][j] = 0.0;
			if (d[i][j] > highest) highest = d[i][j];
		}
	}

	solidID = glGenLists(2);
	wireFrameID = solidID + 1;
	createSolidDisplayList();
	createWireframeDisplayList();

}
