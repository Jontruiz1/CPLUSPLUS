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
bool find_solution(PuzzleState initial, PuzzleState goal, vector<PuzzleMove>& solution);
PuzzleState PuzzleState::NullState = PuzzleState(0, 0);

int main() {
	int grid_size;
	vector<PuzzleMove> solution;
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
			cout << "Solution:" << endl;
			for (auto a : solution) {
				cout << a.getState();
			}
		}
		else {
			cout << "No solution found";
		}
	}
}

bool member_of(PuzzleState curr, vector<PuzzleMove> temp) {
	for (auto a : temp) {
		if (a.getState() == curr) {
			return true;
		}
	}
	return false;
}

vector<PuzzleMove> expand(PuzzleState& curr_s, vector<PuzzleMove>& closed) {
	vector<PuzzleMove> fringe;

	if (curr_s.canMoveRight() && !member_of(curr_s.moveBlankRight(), closed)) {
		fringe.push_back(PuzzleMove(curr_s.moveBlankRight(), curr_s, (enum MoveType)(3)));
	}
	if (curr_s.canMoveUp() && !member_of(curr_s.moveBlankUp(), closed)) {
		fringe.push_back(PuzzleMove(curr_s.moveBlankUp(), curr_s, (enum MoveType)(2)));
	}
	if (curr_s.canMoveLeft() && !member_of(curr_s.moveBlankLeft(), closed)) {
		fringe.push_back(PuzzleMove(curr_s.moveBlankLeft(), curr_s, (enum MoveType)(1)));
	}
	if (curr_s.canMoveDown() && !member_of(curr_s.moveBlankDown(), closed)) {
		fringe.push_back(PuzzleMove(curr_s.moveBlankDown(), curr_s, (enum MoveType)(0)));
	}
	
	
	
	
	/*
	cout << "curr: " << endl;
	cout << curr_s;
	
	cout << "children" << endl;
	for (auto a : fringe) {
		cout << a.getState();
	}
	
	system("cls");
	*/
	return fringe;
}

bool find_solution(PuzzleState initial, PuzzleState goal, vector<PuzzleMove>& solution) {
	PuzzleMove curr_move = PuzzleMove(initial, PuzzleState::NullState, nullMove);
	PuzzleState curr_s = curr_move.getState();
	vector<PuzzleMove> fringe = { curr_move }; // current nodes that we are traversing, like the stack
	vector<PuzzleMove> closed; // nodes no longer traversing, like visited nodes5
	vector<PuzzleMove> temp;

	while (!fringe.empty()) {
		curr_move = fringe.back();
		curr_s = curr_move.getState();
		fringe.pop_back();

		if (curr_s == goal) {
			solution.push_back(curr_move);
			for (auto it = closed.rbegin(); it != closed.rend() && !(it->getState().isNullState()); ++it) {
				if (it->getState() == curr_move.getParent()) {
					solution.push_back(*it);
					curr_move = *it;
					it = closed.rbegin();
				}
			}
			return true;
		}
		else {
			if (!member_of(curr_s, closed)) {
				closed.push_back(curr_move);
				temp = expand(curr_s, closed);
				fringe.insert(fringe.begin(), temp.begin(), temp.end());
			}
		}
	}

	return false;

}

/*
bool find_solution(PuzzleState initial, PuzzleState goal, vector<PuzzleMove>&solution) {
	PuzzleMove curr_move(initial, PuzzleState::NullState , nullMove);
	PuzzleState curr_s;
	vector<PuzzleMove> fringe = {curr_move}; // current nodes that we are traversing, like the stack
	vector<PuzzleMove> closed; // nodes no longer traversing, like visited nodes5
	
	while (!fringe.empty()) {
		curr_move = fringe.back();
		curr_s = curr_move.getState();
		fringe.pop_back();


		if (curr_move.getState() == goal) {
			solution.push_back(curr_move);
			while (curr_move.getParent() != PuzzleState::NullState) {
				for (auto a : closed) {
					if (a.getState() == curr_move.getParent()) {
						curr_move = a;
						solution.push_back(curr_move);
					}
				}
				
			}
			return true;
		}
		else {
			if (!member_of(curr_s, closed)) {
				closed.push_back(curr_move);

				if (curr_s.canMoveRight() && !member_of(curr_s.moveBlankRight(), closed)) {
					fringe.push_back(PuzzleMove(curr_s.moveBlankRight(), curr_s, (enum MoveType)(3)));
				}
				if (curr_s.canMoveUp() && !member_of(curr_s.moveBlankUp(), closed)) {
					fringe.push_back(PuzzleMove(curr_s.moveBlankUp(), curr_s, (enum MoveType)(2)));
				}
				if (curr_s.canMoveLeft() && !member_of(curr_s.moveBlankLeft(), closed)) {
					fringe.push_back(PuzzleMove(curr_s.moveBlankLeft(), curr_s, (enum MoveType)(1)));
				}
				if (curr_s.canMoveDown() && !member_of(curr_s.moveBlankDown(), closed)) {
					fringe.push_back(PuzzleMove(curr_s.moveBlankDown(), curr_s, (enum MoveType)(0)));
				}
			}
		}
	}
	return false;
}
*/
