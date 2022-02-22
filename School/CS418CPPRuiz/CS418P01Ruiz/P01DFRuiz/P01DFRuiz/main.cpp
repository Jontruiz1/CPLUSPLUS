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
list<PuzzleMove> expand(PuzzleState initial);
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
		if (find_solution(initial, goal, solution) ){
			for (auto i : solution) {
				cout << i.getState();
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

bool find_solution(PuzzleState initial, PuzzleState goal, list<PuzzleMove>&solution) {
	PuzzleMove curr_move(initial, initial, nullMove);
	list<PuzzleMove> fringe = {curr_move}; // current nodes that we are traversing, like the stack
	list<PuzzleMove> closed; // nodes no longer traversing, like visited nodes
	PuzzleState curr_s;

	while (!fringe.empty()) {
		list<PuzzleMove> result;
		curr_move = fringe.front();
		fringe.pop_front();
		curr_s = curr_move.getState();

		if (curr_s == goal) {
			// something here to initialize solution
			solution.push_front(curr_move);
			for (auto a : closed) {
				if (a.getState() == curr_move.getParent()) {
					solution.push_front(a);
					curr_move = a;
				}
			}
			return true;
		}
		else {
			closed.push_back(curr_move);

			if (curr_s.canMoveDown() && !member_of(curr_s.moveBlankDown(), closed)) {
				result.push_back(PuzzleMove(curr_s.moveBlankDown(), curr_s, (enum MoveType)0));
			}
			if (curr_s.canMoveLeft() && !member_of(curr_s.moveBlankLeft(), closed)) {
				result.push_back(PuzzleMove(curr_s.moveBlankLeft(), curr_s, (enum MoveType)1));
			}
			if (curr_s.canMoveUp() && !member_of(curr_s.moveBlankUp(), closed)) {
				result.push_back(PuzzleMove(curr_s.moveBlankUp(), curr_s, (enum MoveType)2));
			}
			if (curr_s.canMoveRight() && !member_of(curr_s.moveBlankRight(), closed)) {
				result.push_back(PuzzleMove(curr_s.moveBlankRight(), curr_s, (enum MoveType)3));
			}
			fringe.insert(fringe.begin(), result.begin(), result.end());
		}
	}
	return false;

}
