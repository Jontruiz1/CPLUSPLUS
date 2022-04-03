#ifndef _PUZZLEMOVE_
#define _PUZZLEMOVE_

#include "PuzzleState.h"
using namespace std;

enum MoveType { down, left, up, right, nullMove };

class PuzzleMove {
public:
	PuzzleMove() { }
	PuzzleMove(PuzzleState s, PuzzleState p, MoveType m, PuzzleState g, int cost) : state(s), parent(p), move(m), gN(cost) { 
		hN = setHN(s, g);
		fN = hN + gN; 
	}
	PuzzleState& getState() { return state; }
	PuzzleState& getParent() { return parent; }
	MoveType getMoveName() { return move; }
	int getGN() const { return gN; }
	int getFN() const { return fN; }
	int setHN(PuzzleState& s, PuzzleState& g);

private:
	PuzzleState state;
	PuzzleState parent;
	MoveType move;

	int hN;
	int gN;
	int fN;
};



#endif

