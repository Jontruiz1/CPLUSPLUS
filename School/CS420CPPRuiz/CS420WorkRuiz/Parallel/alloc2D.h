/* alloc2D.h */

//
// Matrix allocation functions
//

#pragma once

//
// New2dMatrix: allocates a 2D matrix of size ROWSxCOLS, which is really a 1D array of 
// row pointers into a large, contiguous block of 1D memory.  For example, in ASCII
// art, here's a 3x5 array:
//
//              -------------------------------
//              | | | | | | | | | | | | | | | |
//              -------------------------------
//               ^         ^         ^
//               |         |         |
//   ---         |         |         |
//   |-----------          |         |
//   ---                   |         |
//   |----------------------         | 
//   ---                             |
//   |--------------------------------
//   ---
//
// Why?  Turns out this will make a huge difference when using MPI, since 
// it will allow multiple rows to be sent in one message.
//
template <class T>T **New2dMatrix(int ROWS, int COLS)
{
	T **matrix; 
	T  *elements;

	//
	// for efficiency of both allocation and transmission, we allocate the matrix
	// as 1 large chunk of memory, then set the row pointers into this chunk:
	//
  matrix = new T*[ROWS];
  elements = new T[ROWS * COLS];

	for (int r = 0; r < ROWS; r++)
		matrix[r] = &elements[r * COLS];

	return matrix;
}


//
// Delete2dMatrix: returns memory associated with 2D matrix returned by New2dMatrix.
//
template <class T>void Delete2dMatrix(T **matrix)
{
	delete[] matrix[0];
	delete[] matrix;
}
