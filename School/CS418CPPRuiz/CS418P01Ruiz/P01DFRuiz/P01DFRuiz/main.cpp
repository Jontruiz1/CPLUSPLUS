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
bool find_solution(PuzzleState, PuzzleState, list<PuzzleMove>&);


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
				cout << (i).getState() << endl;
			}
		}
	}
}

bool find_solution(PuzzleState initial, PuzzleState goal, list<PuzzleMove>& solution) {
	list<PuzzleMove*> open;
	list<PuzzleMove*> closed;
	PuzzleMove* curr_move = new PuzzleMove(initial, initial, nullMove);
	open.push_back(curr_move);
	while (!open.empty()) {
		curr_move = open.back();
		closed.push_back(curr_move);
		open.pop_back();

		if (curr_move->getState() == goal) {
			cout << "Solution found";
			return true;
		}
		else {
			while (curr_move != nullptr) {
				PuzzleState curr = curr_move->getState();

				if (curr.canMoveDown()) {
					curr_move = new PuzzleMove(curr.moveBlankDown(), curr, (enum MoveType)0);
					open.push_front(curr_move);
				}
				else if (curr.canMoveLeft()) {
					curr_move = new PuzzleMove(curr.moveBlankLeft(), curr, (enum MoveType)1);
					open.push_front(curr_move);
				}
				else if (curr.canMoveUp()) {
					curr_move = new PuzzleMove(curr.moveBlankUp(), curr, (enum MoveType)2);
					open.push_front(curr_move);
				}
				else {
					curr_move = new PuzzleMove(curr.moveBlankRight(), curr, (enum MoveType)3);
					open.push_front(curr_move);
				}

			}
		}

	}

	return false;
}