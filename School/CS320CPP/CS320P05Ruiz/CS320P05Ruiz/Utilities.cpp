#ifndef SUPPORT_FUNCTIONS_DEF
#define SUPPORT_FUNCTIONS_DEF
/**
* Internal method to test if a positive number is prime.
* Not an efficient algorithm.
*/
bool isPrime(int n)
{
	if (n == 2 || n == 3)
		return true;

	if (n == 1 || n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

/**
* Internal method to return a prime number at least as large as n.
* Assumes n > 0.
*/
unsigned nextPrime(int n)
{
	if (n % 2 == 0)
		++n;

	for (; !isPrime(n); n += 2)
		;

	return n;
}
#endif
//#endif  //SUPPORT_FUNCTIONS
//template <typename T> 
//void printTableLoads(ostream & fout = cout, const vector<HashTableLinear<unsigned>> & h, unsigned num_of_tables, unsigned num_of_keys)
//{
//	for (unsigned i = 1; i < num_of_tables; i++) {
//		fout << h[i].getNumBuckets() << " buckets."
//			<< " load factor =  " << static_cast<double>(MAX_NUM_KEYS) / h[i].getNumBuckets() << endl;
//	}
//
//} 