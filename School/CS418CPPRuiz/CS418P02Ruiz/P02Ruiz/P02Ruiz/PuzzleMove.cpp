#include "PuzzleMove.h"
//
//void goalPos(const int& curr, const vector<int>& gTiles, const int& rows, const int& cols, int& yrow, int& ycol) {
//	int curr_pos;
//
//	for (int row = 0; row < rows; ++row) {
//		for (int col = 0; col < cols; ++col) {
//			curr_pos = (rows * row) + col;
//
//			if (curr == gTiles[curr_pos]) {
//				yrow = row;
//				ycol = col;															// sets row and cols of goal tile
//				return;
//			}
//		}
//	}
//}
//
//int PuzzleMove::setHN(PuzzleState& s, PuzzleState& g) {
//	
//	vector<int> sTiles = s.getTiles();												// gets the current tile arrays
//	vector<int> gTiles = g.getTiles();			
//
//	int curr_pos, yrow, ycol;
//	int rows = s.getRows();
//	int cols = s.getRows();															// They're the same because it's NxN, probably should change at some point
//	int sSum = 0;
//
//	for (int row = 0; row < rows; ++row) {
//		for (int col = 0; col < cols; ++col) {
//			curr_pos = (rows * row) + col;											// gets current position in the 1D array
//
//			if (sTiles[curr_pos] != gTiles[curr_pos] && sTiles[curr_pos] != 0) {		
//				goalPos(sTiles[curr_pos], gTiles, rows, cols, yrow, ycol);			// find the row and col of goal position of current tile
//				sSum += (abs(row - yrow) + abs(col - ycol));						// add the distance of current tile
//			}
//		}
//	}
//
//	return sSum;
//}




int PuzzleMove::setHN(PuzzleState& s, PuzzleState& g) {

	vector<int> sTiles = s.getTiles();												// gets the current tile arrays
	vector<int> gTiles = g.getTiles();
	size_t size = sTiles.size();

	int srow, scol, grow, gcol;
	int N = s.getRows();															// from NxN
	int sSum = 0;																	// total sum

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sTiles[i] == gTiles[j] && sTiles[i] != 0 && gTiles[j] != 0) {
				srow = (i % N);
				grow = (j % N);

				scol = (i / N);
				gcol = (j / N);

				sSum += abs(srow - grow) + abs(scol - gcol);
				break;
			}
		}
	}

	return sSum;
}


