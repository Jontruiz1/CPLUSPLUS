#ifndef _PUZZLEMOVE_
#define _PUZZLEMOVE_

#include "PuzzleState.h"
using namespace std;

enum MoveType { down, left, up, right, nullMove };

class PuzzleMove {
public:
	PuzzleMove() { }
	PuzzleMove(PuzzleState curr, PuzzleState& parent, PuzzleState& goal, MoveType m, int cost) : state(curr), parent(parent), move(m), gN(cost), hN(setHN(curr, goal)), fN(gN + hN) {}
	PuzzleState& getState() { return state; }
	PuzzleState& getParent() { return parent; }
	MoveType getMoveName() { return move; }
	const int getGN() { return gN; }
	const int getFN() const { return fN; }
	int setHN(PuzzleState& curr, PuzzleState& goal);

private:
	PuzzleState state;
	PuzzleState parent;
	MoveType move;

	int gN;
	int hN;
	int fN;
};
#endif

