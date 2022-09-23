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

		// move values from rhs's list into left hand side's list
		// for the primitives we can just reassign them on the left side

		return *this;
	}

	//assignment operators +- and use member function binary op + for this class
	Polynomial<NumberType> operator+=(const Monomial<NumberType>& m) {

		insert_in_poly(*this, m);
		return *this;
	}
	Polynomial<NumberType> operator+=(const Polynomial<NumberType>& rhs) {

		// for each element in rhs, take it, add it into the polynomial on the left
		// probably should use +=
		for (const auto& i : rhs.term_list) {
			*this += i;
		}
		return *this;


	}
	const Polynomial<NumberType> operator+ (const Monomial<NumberType>& m)const {
		//should probably also use += somehow
		return Polynomial<NumberType>(*this) += m;
	}
	const Polynomial<NumberType> operator+ (const Polynomial<NumberType>& rhs) const {
		// should probably use +=
		return Polynomial<NumberType>(*this) += rhs;
	}
	Polynomial<NumberType> operator-=(const Monomial<NumberType>& m) {
		// change the coefficient of m
		// we can still use insert_in_poly

		Monomial<NumberType> temp(m);
		temp.assign_coefficient(-temp.coefficient());
		*this += temp;

		return *this;

	}
	Polynomial<NumberType> operator-=(const Polynomial<NumberType>& rhs){

		//similar to +=
		// for each element in rhs, -= on each one
		for (const auto& i : rhs.term_list) {
			*this -= i;
		}
		return *this;

	}
	const Polynomial<NumberType> operator- (const Monomial<NumberType>& m)const {
		// we just defined -=, should probably use -=

		return Polynomial<NumberType>(*this) -= m;

	}
	const Polynomial<NumberType> operator- (const Polynomial<NumberType>& rhs) const {
		// we just defined -=, should probably use -=
		return Polynomial<NumberType>(*this) -= rhs;
	}
	Polynomial<NumberType> operator*=(const Monomial<NumberType>& m) {
		// 2x^5 + 3x^4
		// 2x^2 (2x^5 + 3x^4)

		for (const auto& i : (*this).term_list) {
			i.assign_coefficient(m.coefficient() * i.coefficient());
			i.assign_degree(m.degree() + i.degree());
		}

		return *this;

	}
	Polynomial<NumberType> operator*=(const Polynomial<NumberType>& rhs) {
		// 2x^5 + 3x^4 (2x^5 + 3x^4)
		// nested for loop
		// coefficient of left * rhs coefficient
		// degree of left + degree of right
		// insert_in_poly()

	}
	const Polynomial<NumberType> operator*(const Monomial<NumberType>& m) const;
	const Polynomial<NumberType> operator*(const Polynomial<NumberType>& rhs)const;
	const NumberType evaluate(NumberType x) const {
		// x= 5
		// 2x^5 + 3x^4 

	}
	bool operator==(const Polynomial<NumberType>& p) const {
		// go through each coefficient and degree of both and compare
	}
	bool operator!=(const Polynomial<NumberType>& p) const;
	int gethighestdegree() const { return highest_degree; }
	void read(istream& in = cin) {
		// keep doing that until coefficient is 0
		// read in a coefficient
		// read in a degree if the coefficient isnt 0
		NumberType coef;
		NumberType deg;


		in >> coef;
		while (coef != 0) {
			in >> deg;

			insert_in_poly(*this, Monomial<NumberType>(coef, deg));
			in >> coef;
		}



	}
	void print(ostream& out = cout) const {

		// print out coefficient^degree for each element in termlist
		// make sure not to print out an extra +/- at the end or beginning
		// 
		string sign;

		for (auto it = term_list.begin(); it != term_list.end(); it++) {
			Monomial<NumberType> curr(*it);
			if (it != term_list.begin()) {
				out << (curr.coefficient() > 0 ? "+" : "-");
			}
			if (curr.coefficient() != 1 && curr.coefficient() != -1) {
				out << curr.coefficient();
			}
			if (curr.degree() != 0) {
				out << "x^" << curr.degree();
			}
		}
	}

private:
	list<Monomial<NumberType> > term_list; //sorted by decreasing degrees
	int number_of_terms;
	int highest_degree;

	//private helper member function
	void insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m) {
		auto it = p.term_list.begin();
		// check p to determine if the term list is empty
		//		number_of_terms and highest_degree will be 0
		//		simply add m to the term_list
		if ((*it).coefficient() == 0 && p.number_of_terms == 1) {
			p.term_list.pop_front();
			p.term_list.push_front(m);
			p.highest_degree = m.degree();
		}
		else {
			// if there are monomials in the list then iterate through the list
			//	to figure out where to insert the new monomial
			p.term_list.push_front(m);
			while (it != p.term_list.end()) {
				Monomial<NumberType> curr_m = *it;
				// 3 cases:
				
				if (curr_m.degree() == m.degree()) {
					// the degree of the monomial matches the degree of a monomial in the list
					//		add the coefficients
					//			if the coefficient goes to 0
					//				you need to handle this case
					//			otherwise update the coefficient for the monomial in the list
				}
				else if (curr_m.degree() < m.degree()) {
					// monomial gets added before another monomial in the term_list
					//		update number_of_terms and possibly highest_degree
					p.term_list.insert(it, m);
					p.number_of_terms++;
					if (m.degree() > p.gethighestdegree()) {
						p.highest_degree = m.degree();
					}


				}
				else {
					// monomial gets added to the end of the term list
					//		update number_of_terms
					it++;
					if (it == p.term_list.end()) {
						p.term_list.insert(it, m);
						p.number_of_terms++;
						

					}
				}
			}
		}
		

		

		

	}

	NumberType power(NumberType x, int n) const {
		NumberType sum = 0;
		for (const auto& m : this->term_list) {

			sum += (m.coefficient() * (power(x, m.degree())));

		}
	}
};

template<typename NumberType>
istream& operator>>(istream& in, Polynomial<NumberType>& rhs) {
	rhs.read(in);
	return in;
}

template<typename NumberType>
ostream& operator<<(ostream& out, const  Polynomial<NumberType>& rhs) {
	rhs.print(out);
	return out;
}
#endif
