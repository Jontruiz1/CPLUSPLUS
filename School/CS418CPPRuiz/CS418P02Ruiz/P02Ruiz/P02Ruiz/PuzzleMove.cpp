#include "PuzzleMove.h"

int PuzzleMove::setHN(PuzzleState& s, PuzzleState& g) {

	vector<int> sTiles = s.getTiles();												// gets the current tile arrays
	vector<int> gTiles = g.getTiles();
	size_t size = sTiles.size();

	int srow, scol, grow, gcol;
	int N = s.getRows();															// from NxN
	int sSum = 0;																	// total sum

	for (int i = 0; i < size; i++) {												// looping through current tiles
		for (int j = 0; j < size; j++) {											// looping through goal tiles
			if (sTiles[i] == gTiles[j] && sTiles[i] != 0) {		// check if the current and goal match and maker sure neither has a 0
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


