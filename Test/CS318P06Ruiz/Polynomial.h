// Polynomial.h -- starter code
#ifndef __POLYNOMIAL_H_
#define __POLYNOMIAL_H_
#include <iostream>
#include <list>
using namespace std;

///////////////////////////////////////////////////////// Monomial Class
// Monomial - class that creates the terms that get inserted in a Polynomial
//	Do not modify
template <typename NumT>
class Monomial {
public:
	Monomial<NumT>(NumT c = 0, int d = 0) : coeff(c), expo(d){ };
	NumT coefficient(void) const { return coeff; };
	int degree(void) const { return expo; };
	void assign_coefficient(const NumT c) { coeff = c; };
	void assign_degree(const int d) { expo = d; };
	
	bool operator==(const Monomial<NumT>& m) const {
		return (coeff == m.coeff && expo == m.expo);
	}
	
	bool operator!=(const Monomial<NumT>& m) const {
		return (coeff != m.coeff || expo != m.expo);
	}
private:
	NumT coeff; // in our case this will be an int
	int	expo;
};

//////////////////////////////////////////////////////Polynomial Class
template <typename NumberType>
class Polynomial
{
public:
	// Default constructor -- DO NOT MODIFY
	Polynomial<NumberType>(NumberType c = 0, int d = 0) {
		const Monomial<NumberType> m(c, d);
		term_list.push_back(m); //creates at least one monomial
		number_of_terms = 1;
		highest_degree = d;
	}
	
	// Type conversion construct -- DO NOT MODIFY
	Polynomial<NumberType>(const Monomial<NumberType>& m) { 
		term_list.push_back(m);
		number_of_terms = 1;
		highest_degree = m.degree();
	}

	// Destructor - use default destructors and list's destructor -- DO NOT MODIFY
	~Polynomial<NumberType>() { term_list.clear(); }

	// Copy Constructor -- DO NOT MODIFY
	Polynomial<NumberType>(const Polynomial<NumberType>& rhs)  
		: term_list(rhs.term_list),
		number_of_terms(rhs.number_of_terms),
		highest_degree(rhs.highest_degree) {}

	int gethighestdegree() const { return highest_degree; }

	// COMPLETE ALL OF THE FOLLOWING
	const Polynomial<NumberType>& operator=(const Polynomial<NumberType>& rhs); // copy assignment
	const Polynomial<NumberType>& operator=(Polynomial<NumberType>&& rhs);// move assignment
	
	// ADDITION																			
	Polynomial<NumberType> operator+=(const Monomial<NumberType>& m);
	Polynomial<NumberType> operator+=(const Polynomial<NumberType>& rhs);
	const Polynomial<NumberType> operator+ (const Monomial<NumberType>& m)const;
	const Polynomial<NumberType> operator+ (const Polynomial<NumberType>& rhs) const;

	// SUBTRACTION
	Polynomial<NumberType> operator-=(const Monomial<NumberType>& m);
	Polynomial<NumberType> operator-=(const Polynomial<NumberType>& rhs);
	const Polynomial<NumberType> operator- (const Monomial<NumberType>& m)const;
	const Polynomial<NumberType> operator- (const Polynomial<NumberType>& rhs) const;

	// MULTIPLICATION
	Polynomial<NumberType> operator*=(const Monomial<NumberType>& m);
	Polynomial<NumberType> operator*=(const Polynomial<NumberType>& rhs);
	const Polynomial<NumberType> operator*(const Monomial<NumberType>& m) const;
	const Polynomial<NumberType> operator*(const Polynomial<NumberType>& rhs)const;

	// EVALUATION POLYNOMIAL
	const NumberType evaluate(NumberType x) const;

	// EQUALITY TESTS
	bool operator==(const Polynomial<NumberType>& p) const;
	bool operator!=(const Polynomial<NumberType>& p) const;

	// CALLED FROM ISTREAM AND OSTREAM OVERLOADS
	// read() function has responsibility for getting input, creating Monomial object,
	//			and inserting into Polynomial object
	void read(istream& in = cin) {
		NumberType c;
		int d;

		in >> c;
		while (c != 0) {
			in >> d;
			insert_in_poly(*this, Monomial<NumberType>(c, d));
			in >> c;
		}

	}

	// print() function -- make sure you look back at requirements for this
	void print(ostream& out = cout) const {
		for (auto it = term_list.begin(); it != term_list.end(); ++it) {
			cout << it->coefficient() << "x^" << it->degree() << " + ";
		}
	}

private:
	list<Monomial<NumberType> > term_list; //SORTED BY DECREASING DEGREES
	int number_of_terms;
	int highest_degree;

	//private helper member function -- review notes below function prototype
	void insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m) {
		if (p.term_list.empty()) {
			p.term_list.push_back(m);
			p.number_of_terms++;
			p.highest_degree = m.degree();
		}
		else {
			if (p.term_list.begin()->coefficient() == 0) {
				p.term_list.erase(p.term_list.begin());
				p.number_of_terms--;
			}


			for (auto itr = p.term_list.begin(); itr != term_list.end(); ++itr) {
				if (itr->degree() == m.degree()) {
					itr->assign_coefficient(itr->coefficient() + m.coefficient());
					if (itr->coefficient() == 0) {
						p.term_list.erase(itr);
						p.number_of_terms--;
						p.highest_degree = p.term_list.front().degree();
					}
					break;
				}
				else if (m.degree() > itr->degree()) {
					p.term_list.insert(itr, m);
					p.number_of_terms++;
					if (p.highest_degree < m.degree()) {
						p.highest_degree = m.degree();
					}
					break;
				}
				else {
					p.term_list.push_back(m);
					number_of_terms++;
					break;
				}
			}
		}
	}
	/*
		check p to determine if the term list is empty
			-	number_of_terms and highest_degree will be 0
			-	simply add m to the term_list


		if there are monomials in the list then iterate through the list
			to figure out where to insert the new monomial

			3 cases:
			-	the degree of the monomial matches the degree of a monomial in the list
				-	add the coefficients
					-	if the coefficient goes to 0, you need to handle this case
					-	otherwise update the coefficient for the monomial in the list

			-	monomial gets added before another monomial in the term_list
				-	update number_of_terms and possibly highest_degree

			-	monomial gets added to the end of the term list
				-	update number_of_terms
	*/
	
	// Used in evaluate member function
	NumberType power(NumberType x, int n) const;
};

// DO NOT MODIFY
template<typename NumberType>
istream& operator>>(istream& in, Polynomial<NumberType>& rhs) {
	rhs.read();
	return in;
}

// DO NOT MODIFY
template<typename NumberType>
ostream& operator<<(ostream& out, const  Polynomial<NumberType>& rhs) {
	rhs.print();
	return out;
}

#endif