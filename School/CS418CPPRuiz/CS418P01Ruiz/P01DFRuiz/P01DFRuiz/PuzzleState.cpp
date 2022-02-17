#include <iostream>
#include "PuzzleState.h"


bool PuzzleState::operator==(const PuzzleState& rhs) const {
	return rhs.tiles == this->tiles;
}

const PuzzleState& PuzzleState::operator=(const PuzzleState& rhs) {
	this->rows = rhs.rows;
	this->cols = rhs.cols;
	this->tiles = rhs.tiles;
	this->blank_position_row = rhs.blank_position_row;
	this->blank_position_col = rhs.blank_position_col;

	return *this;
}
void PuzzleState::read(istream& in) {

	for (size_t i = 0; i < rows * cols; ++i) {
		in >> tiles[i];
		
	}

}

// 1 3 5 4 2 0 7 8 6
void PuzzleState::print(ostream& out) {

	for (size_t i = 0; i < rows * cols; ++i) {
		if (i % cols == 0 && i != 0) out << endl;
		out << tiles[i] << " ";
	}
	out << endl << endl;
}

istream& operator>>(istream& in, PuzzleState& rhs) {
	rhs.read(in);
	return in;
}

ostream& operator<<(ostream& out, PuzzleState& rhs) {
	rhs.print(out);
	return out;
}