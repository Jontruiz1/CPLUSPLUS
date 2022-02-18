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

	// declare an int to store size of grid
	// declare list of puzzle moves which is like the solution
	// declare start state and goal state of a size
	// ask to enter state state and goal state
	// check if start state and goal state equal if yes
	// print out true or whatever
	// if not goal state, call find solution which prints out solution based on if there is one
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

	/*
	if (initial == goal) {
		cout << "Solution found immediately: start state is the goal state";
	}
	*/

	initial.moveBlankLeft();
	cout << initial;

	/*
	else {
		if (find_solution(initial, goal, solution)) {
			for (auto i : solution) {
				cout << i.getMoveName() << endl << i.getState();
			}
		}
		else {
			cout << "No solution found." << endl;
		}
	}
	*/

}
// bool to check if something is a member of puzzle moves

bool find_solution(PuzzleState initial, PuzzleState goal, list<PuzzleMove>& solution) {
	/*
	list<PuzzleMove*> open;
	list<PuzzleMove*> closed;
	list<PuzzleMove*> temp;
	PuzzleMove* curr_move = new PuzzleMove(initial, initial, nullMove); // set the current state to the initial first state
	open.push_back(curr_move); // put the initial state into the open list

	

	// grab the curr node and push into the closed list
	// 4 if statements, all very similar
	//	if curr move can move down, if true create child state from top of find solution, make call on current state to move
	//	blank down which gets put into curr state
	//	if child state is member of open or closed, don't mess with it.
	// grab goal node, say whos parent, push curr move onto solution, get parent state etc

	
	PuzzleState curr = curr_move->getState();
	if (curr.canMoveDown()) {
		curr_move = new PuzzleMove(curr.moveBlankDown(), curr, (enum MoveType)0);
	}
	else if (curr.canMoveLeft()) {
		curr_move = new PuzzleMove(curr.moveBlankLeft(), curr, (enum MoveType)1);
	}
	else if (curr.canMoveUp()) {
		curr_move = new PuzzleMove(curr.moveBlankUp(), curr, (enum MoveType)3);
	}
	else if (curr.canMoveRight()) {
		curr_move = new PuzzleMove(curr.moveBlankRight(), curr, (enum MoveType)2);
	}*/

	// open list of puzzle moves
	// closed list of puzzle moves
	// puzzle move called curr move
	// parent state
	// child state
	// if bfs queue start state to back, first insertion into open list
	// if frontier still has stuff on it and you haven't found goal node, set up a while loop
	// everything in while loop
	// pull everything off 
	// from curr move get state
	// 
	// if open size gets greater than 1000, start printing out size just to test
	// build solution list, if current state == goal, done
	// set up so that you create list that becomes the solution list return true
	// 
	// else
	
	
	return true;
}