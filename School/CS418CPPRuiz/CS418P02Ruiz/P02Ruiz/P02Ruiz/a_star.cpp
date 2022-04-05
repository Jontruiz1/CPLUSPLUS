/*
* Jonathan Ruiz
* CS418AStarP02
* 
* Most of the changes made with the PuzzleState and PuzzleMove classes. The heuristic function is created in PuzzleMove.cpp
*/

#include <iostream>
#include <queue>
#include "PuzzleMove.h"
#include "PuzzleState.h"


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
		cout << "Solution found immediately: start state is the goal state" << endl;
	}
	else {
		if (find_solution(initial, goal, solution)) {
			for (auto it = solution.rbegin(); it != solution.rend(); ++it) {
				cout << (it->getMoveName() == 0 ? "down\n" : it->getMoveName() == 1 ? "left\n" : it->getMoveName() == 2 ? "up\n" : it->getMoveName() == 3 ? "right\n" : "") << endl << it->getState();
				//cout << (it->getMoveName() == 0 ? "down\n" : it->getMoveName() == 1 ? "left\n" : it->getMoveName() == 2 ? "up\n" : it->getMoveName() == 3 ? "right\n" : "") << endl;
			}
		}
		else {
			cout << "No solution found";
		}
	}
}

// I probably could have used the .find function in retrospect
bool member_of(const PuzzleState curr, const vector<PuzzleMove>& temp) {
	for (auto a : temp) {
		if (a.getState() == curr) {
			return true;
		}
	}
	return false;
}

// checking if the blank space can move in the 4 directions, if it can, push that movement into the fringe
vector<PuzzleMove> expand(PuzzleMove& curr_m, PuzzleState& goal, vector<PuzzleMove>& closed) {
	vector<PuzzleMove> fringe;
	PuzzleState curr_s = curr_m.getState();
	int curr_cost = curr_m.getGN();
	
	if (curr_s.canMoveDown() && !member_of(curr_s.moveBlankDown(), closed)) {
		fringe.push_back(PuzzleMove(curr_s.moveBlankDown(), curr_s, goal, down, curr_cost + 1));
	}
	if (curr_s.canMoveLeft() && !member_of(curr_s.moveBlankLeft(), closed)) {
		fringe.push_back(PuzzleMove(curr_s.moveBlankLeft(), curr_s, goal, MoveType(1), curr_cost + 1));
	}
	if (curr_s.canMoveUp() && !member_of(curr_s.moveBlankUp(), closed)) {
		fringe.push_back(PuzzleMove(curr_s.moveBlankUp(), curr_s, goal, up, curr_cost + 1));
	}
	if (curr_s.canMoveRight() && !member_of(curr_s.moveBlankRight(), closed)) {
		fringe.push_back(PuzzleMove(curr_s.moveBlankRight(), curr_s, goal,  MoveType(3), curr_cost+1));
	}

	return fringe;
}

// comparison operator for the priority queue to sort
bool operator<(const PuzzleMove& move1, const PuzzleMove& move2) {
	return (move1.getFN() > move2.getFN());
}


bool find_solution(PuzzleState initial, PuzzleState goal, vector<PuzzleMove>& solution) {
	PuzzleMove curr_move = PuzzleMove(initial, PuzzleState::NullState, goal, nullMove, 0); // like the current node we're at
	PuzzleState curr_s = curr_move.getState();					// the current state 
	priority_queue<PuzzleMove> fringe;							// current nodes that we are traversing, like the stack
	vector<PuzzleMove> closed;									// nodes no longer traversing, this will contain the pain used to get to the solution
	vector<PuzzleMove> temp;									// used to hold the result fromn the expansion of the nodes
	int nodes_expanded = 0;
	fringe.push(curr_move);

	while (!fringe.empty()) {
		curr_move = fringe.top();								// get the first element in the vector
		curr_s = curr_move.getState();							// get current state
		fringe.pop();											// pop the first element

		if (curr_s == goal) {
			solution.push_back(curr_move);						// push current node into solution
			
			// build solution vector
			for (auto it = closed.rbegin(); it != closed.rend() && !(it->getState().isNullState()); it++) {
				if (it->getState() == curr_move.getParent()) {
					solution.push_back(*it);
					curr_move = *it;
					it = closed.rbegin();
				}
			}

			cout << "Solution:" << endl;
			return true;
		}
		else {
			// 1 3 5 4 2 0 7 8 6
			// make sure the curr state not already visited
			if (!member_of(curr_s, closed)) {
				nodes_expanded++;
				closed.push_back(curr_move);
				temp = expand(curr_move, goal,  closed);
				for (PuzzleMove& move : temp) { fringe.push(move); }			// I can't use insert which makes me sad but this works too
			}
		}
	}


	return false;

}