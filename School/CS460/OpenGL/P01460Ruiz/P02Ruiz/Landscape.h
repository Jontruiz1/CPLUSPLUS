#pragma once



class Landscape {
public:
	void create(double rug);
	void createSolidDisplayList();
	void createWireframeDisplayList();
	void drawTriangle(int x1, int z1, int x2, int z2, int x3, int z3);
	Landscape(int r, int c);
private:
	int rows;
	int columns;
	double unused;
};