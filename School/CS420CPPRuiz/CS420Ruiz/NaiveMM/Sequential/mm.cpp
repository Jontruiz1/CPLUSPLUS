/* mm.cpp */

//
// Matrix multiplication code
//
// There's a naive version and a more cache-friendly version.  An even better version
// would block-multiply to take full advantage of the cache.  For more details, see
// http://www.cs.rochester.edu/~sandhya/csc252/lectures/lecture-memopt.pdf
//

#include <iostream>
#include <string>

#include "alloc2D.h"
#include "mm.h"

using namespace std;


//
// NaiveMatrixMultiply:
//
// Computes and returns C = A * B, where matrices are NxN.
//
// NOTE: this is the naive implementation of MM, which multiplies rows by 
// columns, and thus doesn't take full advantage of the memory hierarchy.
//
double** NaiveMatrixMultiply(double** const A, double** const B, int N)
{
  double** C = New2dMatrix<double>(N, N);

  //
  // For every row i of A and column j of B:
  //
  for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			C[i][j] = 0.0;

			for (int k = 0; k < N; k++)
				C[i][j] += (A[i][k] * B[k][j]);
		}

	return C;
}
