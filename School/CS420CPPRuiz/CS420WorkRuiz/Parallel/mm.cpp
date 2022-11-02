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
#include <thread>
#include <algorithm>
#include <vector>

#include "alloc2D.h"
#include "mm.h"

using namespace std;


//
// MatrixMultiply:
//
// Computes and returns C = A * B, where matrices are NxN.
//
// NOTE: interchanges the j and k loops for better cache behavior.
// Reference:  "Writing Cache Friendly Code", U. of Rochester,
// http://www.cs.rochester.edu/~sandhya/csc252/lectures/lecture-memopt.pdf
//
double** MatrixMultiply(double** const A, double** const B, int N, int numthreads)
{
  double** C = New2dMatrix<double>(N, N);

  //
  // Statically divide the N rows into equally-sized chunks, based
	// on numthreads:
  //
	int rows  = N / numthreads;
	int extra = N % numthreads;
	int start = 0;    // row dimensions for first thread:
	int end   = rows;

	vector<thread> workers;

	//
	// create a set of threads and give each one a chunk (the last thread
	// will get any extra rows left-over if N is not evenly-divisible:):
	//
	for (int t = 1; t <= numthreads; t++)
	{
		if (t == numthreads) // last thread processes any extra rows:
			end += extra;

		//
		// NOTE: for some reason, passing start, end and N as parameters (versus
		// accessing via closure) makes a HUGE difference --- no speedup vs. 
		// linear speedup.  Also passing matrix pointers (C, A, and B) by value
		// makes a difference as well.
		//
		workers.push_back(thread([C, A, B](int start, int end, int N)
			{
				// initialize my chunk of result:
				for (int i = start; i < end; i++)
					for (int j = 0; j < N; j++)
						C[i][j] = 0.0;

				// now multiply:
				for (int i = start; i < end; i++)
					for (int k = 0; k < N; k++)
						for (int j = 0; j < N; j++)
							C[i][j] += (A[i][k] * B[k][j]);

			}, start, end, N)
		);

		start = end;
		end   = start + rows;
	}//for

	//
	// wait for threads to finish:
	//
	for_each(workers.begin(), workers.end(), [](thread &t)
		{
			t.join();
		}
	);

	//
	// done, return answer:
	//
	return C;
}

