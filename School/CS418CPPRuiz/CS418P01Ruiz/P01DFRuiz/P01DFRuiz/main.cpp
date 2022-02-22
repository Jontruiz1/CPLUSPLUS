/*
* Jonathan Ruiz
* CS418DFSP01
*/

#include <iostream>
#include <vector>
#include <list>
#include "PuzzleMove.h"
#include "PuzzleState.h"



// protoype for find solution returning true or false
// args are 2 puzzle states and list of puzzle moves
// find next parent, 
// takes reference to puzzle state and figures out who the parent is
list<PuzzleMove> expand(PuzzleState initial, list<PuzzleMove>& solution);
bool find_solution(PuzzleState initial, PuzzleState goal, list<PuzzleMove>& solution);


int main() {
	int grid_size;
	list<PuzzleMove> solution;
	PuzzleState initial;
	PuzzleState goal;
	PuzzleState temp;

	cout << "Enter number of rows and columns: ";
	cin >> grid_size;
	initial = PuzzleState(grid_size, grid_size);
	goal = PuzzleState(grid_size, grid_size);

	cout << endl;

	cout << "Enter Start State row by row: ";
	cin >> initial;
	cout << initial;

	cout << "Enter Goal State row by row: ";
	cin >> goal;
	cout << goal;



	if (initial == goal) {
		cout << "Solution found immediately: start state is the goal state";
	}
	else {
		if (find_solution(initial, goal, solution)) {
			for (auto i : solution) {
				cout << (i).getMoveName() << endl << (i).getState() << endl;
			}
		}
		else {
			cout << "No solution found";
		}
	}
}

bool member_of(PuzzleState curr, list<PuzzleMove> temp) {
	for (auto a : temp) {
		if (a.getState() == curr) return true;
	}
	return false;
}
list<PuzzleMove> expand(PuzzleState initial) {
	list<PuzzleMove> neighbors;
	PuzzleMove s;
}
bool find_solution(PuzzleState initial, PuzzleState goal, list<PuzzleMove>&solution) {
	list<PuzzleMove> open; // current nodes that we are traversing, like the stack
	list<PuzzleMove> closed; // nodes no longer traversing, like visited nodes
	list<PuzzleMove> result;
	PuzzleMove curr_move(initial, initial, nullMove);
}
