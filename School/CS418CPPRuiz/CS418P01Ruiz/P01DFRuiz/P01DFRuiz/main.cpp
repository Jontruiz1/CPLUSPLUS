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
<<<<<<< Updated upstream


=======
	
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
			for (auto i : solution) {
				cout <<  (i).getMoveName() << endl << (i).getState() << endl;
=======
			for (auto a : solution) {
				cout << a.getState() << endl;
>>>>>>> Stashed changes
			}
		}
		else {
			cout << "No solution found";
		}
	}
}
list<PuzzleMove> expand(PuzzleState initial) {
	list<PuzzleMove> neighbors;
	PuzzleMove s;

<<<<<<< Updated upstream
bool member_of(PuzzleState curr, list<PuzzleMove> temp) {
	for (auto a : temp) {
		if (a.getState() == curr) return true;
	}
	return false;
}

bool find_solution(PuzzleState initial, PuzzleState goal, list<PuzzleMove>& solution) {
	list<PuzzleMove> open; // current nodes that we are traversing, like the stack
	list<PuzzleMove> closed; // nodes no longer traversing, like visited nodes
	list<PuzzleMove> result;
	PuzzleMove curr_move(initial, initial, nullMove);
	open.push_back(curr_move);


	while (!open.empty()) {
		curr_move = open.back();
		open.pop_back();
		PuzzleState curr_s = curr_move.getState();
		result.push_back(curr_move);

		if (curr_s.canMoveDown()) {
			curr_move = PuzzleMove(curr_s.moveBlankDown(), curr_s, down);
			open.push_front(curr_move);
		}
		if (curr_s.canMoveLeft()) {
			curr_move = PuzzleMove(curr_s.moveBlankLeft(), curr_s, (enum MoveType)1);
			open.push_front(curr_move);
		}
		if (curr_s.canMoveUp()) {
			curr_move = PuzzleMove(curr_s.moveBlankUp(), curr_s, up);
			open.push_front(curr_move);
		}
		if (curr_s.canMoveRight()) {
			curr_move = PuzzleMove(curr_s.moveBlankRight(), curr_s, (enum MoveType)3);
			open.push_front(curr_move);
		}


=======
	if (initial.canMoveDown()) {
		s = PuzzleMove(initial.moveBlankDown(), initial, down);
		neighbors.push_back(s);
	}
	if (initial.canMoveLeft()) {
		s = PuzzleMove(initial.moveBlankLeft(), initial, (enum MoveType)1);
		neighbors.push_back(s);
	}
	if (initial.canMoveUp()) {
		s = PuzzleMove(initial.moveBlankUp(), initial, up);
		neighbors.push_back(s);
	}
	if (initial.canMoveRight()) {
		s = PuzzleMove(initial.moveBlankRight(), initial, (enum MoveType)3);
		neighbors.push_back(s);
	}
	return neighbors;

}
>>>>>>> Stashed changes

bool member_of(PuzzleMove curr, list<PuzzleMove> closed) {
	if (closed.empty()) {
		return false;
	}

<<<<<<< Updated upstream

	

	return true;
}

=======
	for (auto a : closed) {
		if (curr.getState() == a.getState()) return true;
	}
	return false;
}

bool find_solution(PuzzleState initial, PuzzleState goal, list<PuzzleMove>& solution) {
	PuzzleMove curr_move = PuzzleMove(initial, initial, nullMove);
	
	for(auto v : expand(curr_move, solution))

	

	return false;
}
>>>>>>> Stashed changes
