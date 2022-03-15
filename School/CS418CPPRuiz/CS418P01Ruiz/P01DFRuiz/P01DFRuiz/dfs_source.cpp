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
			cout << "***Solution Found***" << endl;
			for (auto it = solution.rbegin(); it != solution.rend(); ++it) {
				cout << (it->getMoveName() == 0 ? "down\n" : it->getMoveName() == 1 ? "left\n" : it->getMoveName() == 2 ? "up\n" : it->getMoveName() == 3 ? "right\n" : "") << it->getState();
			}
			cout << "Moves: " << solution.size()-1 << endl;
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

// checking if the blank space can move in the 4 directions, if it can, push that movement into the fringe
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
	
	return fringe;
}

// LIFO
bool find_solution(PuzzleState initial, PuzzleState goal, vector<PuzzleMove>& solution) {
	PuzzleMove curr_move = PuzzleMove(initial, PuzzleState::NullState, nullMove); // the current node we're at
	PuzzleState curr_s = curr_move.getState();					// the current state 
	vector<PuzzleMove> fringe = { curr_move };					// current nodes that we are traversing, like the stack
	vector<PuzzleMove> closed;									// nodes no longer traversing, this will contain the pain used to get to the solution
	vector<PuzzleMove> temp;									// used to hold the result fromn the expansion of the nodes
	int nodes_expanded = 0;

	while (!fringe.empty()) {
		curr_move = fringe.back();								// get the most recently inserted element
		curr_s = curr_move.getState();							// get current state
		fringe.pop_back();										// pop the last element5
		closed.push_back(curr_move);

		if (curr_s == goal) {
			solution.push_back(curr_move);						// push current node into solution

			/* starting from beginning of the vector will access the very first node which has a nullstate parent which is not what we want
			   the end of the closed list has the most recently inserted nodes, ie, the ones leading up to the solution.
			   check them to make sure they're actually parents, push if yes and then start again from the end of the list (don't want to miss nodes)
			*/
			for (auto it = closed.rbegin(); it != closed.rend() && !(it->getState().isNullState()); ++it) {
				if (it->getState() == curr_move.getParent()) {
					solution.push_back(*it);
					curr_move = *it;
					it = closed.rbegin();
				}
			}
			
			cout << "Nodes expanded " << nodes_expanded << endl;
			return true;
		}
		else {
			// make sure the curr state not already
			closed.push_back(curr_move);	
			temp = expand(curr_s, closed);
			nodes_expanded++;
			fringe.insert(fringe.end(), temp.begin(), temp.end());
		}

	}

	return false;

}