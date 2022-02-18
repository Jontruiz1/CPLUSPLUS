#include <iostream>
#include "PuzzleState.h"

bool PuzzleState::canMoveUp() {
	return !(blank_position_row - 1 < 0);
}
bool PuzzleState::canMoveDown() {

	return !(blank_position_row + 1 > rows-1);
}
bool PuzzleState::canMoveLeft() {
	return !(blank_position_col - 1 < 0);
}
bool PuzzleState::canMoveRight() {
	return !(blank_position_col + 1 > cols-1);
}


PuzzleState PuzzleState::moveBlankUp() {
	PuzzleState result = *this;
	int zero_pos = (result.rows * result.blank_position_row) + result.blank_position_col;
	int switch_pos = (result.rows * (result.blank_position_row - 1)) + result.blank_position_col;
	int temp = result.tiles[zero_pos];

	swap(result.tiles[zero_pos], result.tiles[switch_pos]);
	result.blank_position_row -= 1;

	return result;
}
PuzzleState PuzzleState::moveBlankDown() {
	PuzzleState result = *this;
	int zero_pos = (result.rows * result.blank_position_row) + result.blank_position_col;
	int switch_pos = (result.rows * (result.blank_position_row + 1)) + result.blank_position_col;
	int temp = result.tiles[zero_pos];

	swap(result.tiles[zero_pos], result.tiles[switch_pos]);
	result.blank_position_row += 1;

	return result;
}
PuzzleState PuzzleState::moveBlankLeft() {
	PuzzleState result = *this;
	int zero_pos = (result.rows * result.blank_position_row) + result.blank_position_col;
	int switch_pos = (result.rows * result.blank_position_row) + (result.blank_position_col-1);
	int temp = result.tiles[zero_pos];

	swap(result.tiles[zero_pos], result.tiles[switch_pos]);
	result.blank_position_col -= 1;


	return result;
}
PuzzleState PuzzleState::moveBlankRight() {
	PuzzleState result = *this;
	int zero_pos = (result.rows * result.blank_position_row) + result.blank_position_col;
	int switch_pos = (result.rows * result.blank_position_row) + (result.blank_position_col + 1);
	int temp = result.tiles[zero_pos];

	swap(result.tiles[zero_pos], result.tiles[switch_pos]);
	result.blank_position_col += 1;


	return result;
}

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
	int k = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j, ++k) {
			in >> tiles[k];
			if (tiles[k] == 0) {
				blank_position_col = j;
				blank_position_row = i;
			}
		}
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