#ifndef __POLYNOMIAL_H_
#define __POLYNOMIAL_H_
#include <iostream>
#include <list>
using namespace std;

template <typename NumT>
class Monomial
{
public:
	Monomial<NumT>(NumT c = 0, int d = 0) : coeff(c), expo(d)
	{ };
	NumT coefficient(void) const { return coeff; };
	int degree(void) const { return expo; };
	void assign_coefficient(const NumT c) { coeff = c; };
	void assign_degree(const int d) { expo = d; };
	bool operator==(const Monomial<NumT>& m) const
	{
		return (coeff == m.coeff && expo == m.expo);
	}
	bool operator!=(const Monomial<NumT>& m) const
	{
		return (coeff != m.coeff || expo != m.expo);
	}
private:
	NumT coeff;
	int	expo;
};

template <typename NumberType>
class Polynomial
{
public:
	Polynomial<NumberType>(NumberType c = 0, int d = 0)
	{
		const Monomial<NumberType> m(c, d);
		term_list.push_back(m); //creates at least one monomial
		number_of_terms = 1;
		highest_degree = d;
	}
	Polynomial<NumberType>(const Monomial<NumberType>& m) //type conversion constructor
	{
		term_list.push_back(m);
		number_of_terms = 1;
		highest_degree = m.degree();
	}
	~Polynomial<NumberType>() { } // use default destructors and list's destructor
	Polynomial<NumberType>(const Polynomial<NumberType>& rhs)   // copy constructor
		: term_list(rhs.term_list), number_of_terms(rhs.number_of_terms), highest_degree(rhs.highest_degree)
	{ }
	//copy assignment
	const Polynomial<NumberType>& operator=(const Polynomial<NumberType>& rhs) {

		// take all the values in rhs
		// assign the left hand side's values to those


	}

	//R-val reference
	const Polynomial<NumberType>& operator=(const Polynomial<NumberType>&& rhs) {


	}

	//assignment operators +- and use member function binary op + for this class
	Polynomial<NumberType> operator+=(const Monomial<NumberType>& m) {

	}
	Polynomial<NumberType> operator+=(const Polynomial<NumberType>& rhs) {


	}
	const Polynomial<NumberType> operator+ (const Monomial<NumberType>& m)const {
	
	}
	const Polynomial<NumberType> operator+ (const Polynomial<NumberType>& rhs) const {

	}
	Polynomial<NumberType> operator-=(const Monomial<NumberType>& m) {

	}
	Polynomial<NumberType> operator-=(const Polynomial<NumberType>& rhs) {


	}
	const Polynomial<NumberType> operator- (const Monomial<NumberType>& m)const {
	
	}
	const Polynomial<NumberType> operator- (const Polynomial<NumberType>& rhs) const {
		
	}
	Polynomial<NumberType> operator*=(const Monomial<NumberType>& m) {

		

		*this *= Polynomial

		return *this;
	}
	Polynomial<NumberType> operator*=(const Polynomial<NumberType>& rhs) {

		//make a temporary polynomial
		//make a temporary monomial

		// assign temporary monomial with the result of i's coefficient * j's coefficient
		// assign temporary monomial with the result of i's degree + j degree
		// insert this temporary monomial into the temporary polynomial

	

		// assign this = temporary polynomial
		return *this;

		
	}
	const Polynomial<NumberType> operator*(const Monomial<NumberType>& m) const;
	const Polynomial<NumberType> operator*(const Polynomial<NumberType>& rhs)const;
	const NumberType evaluate(NumberType x) const {
		// 5x^4 + 3x^2
		// x = 2

	}
	bool operator==(const Polynomial<NumberType>& p) const {
		
	}
	bool operator!=(const Polynomial<NumberType>& p) const;
	int gethighestdegree() const { return highest_degree; }
	void read(istream& in = cin) {


		// reads in a coefficient
		// checks while that coefficient is not 0
		// read in a degree
		// make a monomial out of that coefficient and degree
		// insert it into the list
	
	}
	void print(ostream& out = cout) const {

		// print out coefficient, print out x, print out degree, ^

		// go through each element in the monomial list
		// print out the coefficient
		// print out the x only if the degree is greater than or equal to 1
		// also have to remember to print out the sign and to not print out the sign if its at the start of the list
		// or at the end of the list
		// if the degree of x is 0, we don't print out x

	}

private:
	list<Monomial<NumberType> > term_list; //sorted by decreasing degrees
	int number_of_terms;
	int highest_degree;

	//private helper member function
	void insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m) {
		// check p to determine if the term list is empty
		//		number_of_terms and highest_degree will be 0
		//		simply add m to the term_list


		// if there are monomials in the list then iterate through the list
		//	to figure out where to insert the new monomial

			// 3 cases:
				// the degree of the monomial matches the degree of a monomial in the list
				//		add the coefficients
				//			if the coefficient goes to 0
				//				you need to handle this case
				//			otherwise update the coefficient for the monomial in the list

				// monomial gets added before another monomial in the term_list
				//		update number_of_terms and possibly highest_degree

			

				// monomial gets added to the end of the term list
				//		update number_of_terms

		p.term_list.push_back(m);

	}

	NumberType power(NumberType x, int n) const {
		
	}
};

template<typename NumberType>
istream& operator>>(istream& in, Polynomial<NumberType>& rhs) {
	rhs.read(in);
	return in;
}

template<typename NumberType>
ostream& operator<<(ostream& out, const  Polynomial<NumberType>& rhs) {
	rhs.print(in);
	return out;
}
#endif
