//P06: Polynomial.h
#ifndef __POLYNOMIAL_H_
#define __POLYNOMIAL_H_
#include <iostream>
#include <list>
#include <string>
using namespace std;

template <typename NumT>
class Monomial
{
public:
	Monomial<NumT>(NumT c = 0, int d = 0) : coeff(c), expo(d) { };

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
	NumT coeff;
	int	expo;
};

template <typename NumberType>
class Polynomial
{
public:
	Polynomial<NumberType>(NumberType c = 0, NumberType d = 0) {
		const Monomial<NumberType> m(c, d);
		term_list.push_back(m); //creates at least one monomial
		number_of_terms = 1;
		highest_degree = d;
	}

	//type conversion constructor
	Polynomial<NumberType>(const Monomial<NumberType>& m) {
		term_list.push_back(m);
		number_of_terms = 1;
		highest_degree = m.degree();
	}

	// use default destructors and list's destructor	
	~Polynomial<NumberType>() { term_list.clear(); }

	// copy constructor
	Polynomial<NumberType>(const Polynomial<NumberType>& rhs)
		: term_list(rhs.term_list), number_of_terms(rhs.number_of_terms), highest_degree(rhs.highest_degree)
	{ }

	//copy assignment
	const Polynomial<NumberType>& operator=(const Polynomial<NumberType>& rhs) {
		if (this != &rhs) {
			term_list = rhs.term_list;
			highest_degree = rhs.highest_degree;
			number_of_terms = rhs.number_of_terms;
		}
		return *this;
	}

	//R-val reference		    
	const Polynomial<NumberType>& operator=(const Polynomial<NumberType>&& rhs) noexcept {
		if (this != &rhs) {
			// Free the existing resource.
			term_list.clear();

			// Copy data
			term_list = move(rhs.term_list);
			highest_degree = rhs.highest_degree;
			number_of_terms = rhs.number_of_terms;

			//// release data from rhs
		/*	rhs.term_list.clear();
			rhs.highest_degree = 0;
			rhs.number_of_terms = 0;*/

		}
		return *this;
	}

	//assignment operators +- and use member function binary op + for this class
	Polynomial<NumberType> operator+=(const Monomial<NumberType>& m) {
		insert_in_poly(*this, m);
		return *this;
	}

	Polynomial<NumberType> operator+=(const Polynomial<NumberType>& rhs) {
		for (const auto& m : rhs.term_list) {
			*this += m;
		}
		return *this;
	}

	const Polynomial<NumberType> operator+ (const Monomial<NumberType>& m)const {
		return Polynomial(*this) += m;
	}

	const Polynomial<NumberType> operator+ (const Polynomial<NumberType>& rhs) const {
		return Polynomial(*this) += rhs;
	}

	Polynomial<NumberType> operator-=(const Monomial<NumberType>& m) {
		Monomial<NumberType> tmp = m;
		tmp.assign_coefficient(-(tmp.coefficient()));
		insert_in_poly(*this, tmp);
		return *this;
	}

	Polynomial<NumberType> operator-=(const Polynomial<NumberType>& rhs) {
		for (const auto& m : rhs.term_list) {
			*this -= m;
		}
		return *this;
	}

	const Polynomial<NumberType> operator- (const Monomial<NumberType>& m)const {
		return Polynomial(*this) -= m;
	}

	const Polynomial<NumberType> operator- (const Polynomial<NumberType>& rhs) const {
		return Polynomial(*this) -= rhs;
	}

	Polynomial<NumberType> operator*=(const Monomial<NumberType>& m) {
		Monomial<NumberType> tmp(m);
		auto p = Polynomial<NumberType>(tmp.coefficient(), tmp.degree());
		*this *= p;
		return *this;
	}

	Polynomial<NumberType> operator*=(const Polynomial<NumberType>& rhs) {
		Polynomial<NumberType> p;
		Monomial<NumberType> tmp;

		for (const auto& m1 : this->term_list) {
			for (const auto& m2 : rhs.term_list) {
				tmp.assign_coefficient(m1.coefficient() * m2.coefficient());
				tmp.assign_degree(m1.degree() + m2.degree());
				insert_in_poly(p, tmp);
			}
		}
		*this = p;
		return *this;
	}

	const Polynomial<NumberType> operator*(const Monomial<NumberType>& m) const {
		return Polynomial(*this) *= m;
	}

	const Polynomial<NumberType> operator*(const Polynomial<NumberType>& rhs)const {
		return Polynomial(*this) *= rhs;
	}

	const NumberType evaluate(NumberType x) const {
		int result = 0;

		for (auto& m : this->term_list) {
			result += m.coefficient() * power(x, m.degree());
		}

		return result;
	}

	bool operator==(const Polynomial<NumberType>& p) const {

		if ((this->highest_degree != p.highest_degree) ||
			(this->number_of_terms != p.number_of_terms))
			return false;

		auto tbegin = this->term_list.begin();
		auto tend = this->term_list.end();
		auto pbegin = p.term_list.begin();


		bool result = equal(tbegin, tend, pbegin,
			[](auto& a, auto& b) {
				return ((a.coefficient() == b.coefficient()) &&
					(a.degree() == b.degree()));
			}
		);

		return result;
	}

	bool operator!=(const Polynomial<NumberType>& p) const {
		return !(*this == p);
	}

	int gethighestdegree() const { return highest_degree; }

	void read(istream& in = cin) {
		Monomial<NumberType> tmp;
		auto c = tmp.coefficient();
		auto e = tmp.degree();
		//cout << "\nEnter polynomial values: ";
		in >> c;

		while (c != 0) {
			in >> e;
			tmp.assign_coefficient(c);
			tmp.assign_degree(e);
			insert_in_poly(*this, tmp);
			//cout << c << " " << e << endl;
			in >> c;
		}
	}

	void print(ostream& out = cout) const {
		//out << "  Number of Terms=" << this->number_of_terms
		//	<< "   Highest Degree=" << this->highest_degree
		//	<< "   Terms: ";

		auto polyTerms = this->term_list;

		for (auto it = polyTerms.begin(); it != polyTerms.end(); ++it) {
			auto c = it->coefficient();
			if (it == polyTerms.begin()) {
				if (it->degree() == 0 && c == 0) {
					out << "\n";
					return;
				}
				else {
					if (abs(c) != 1)
						out << c;
					else
						if (c < 0)
							out << "-";
				}
			}
			else {
				if (c < 0)
					out << " - ";
				else
					out << " + ";

				if (abs(c) != 1 || it->degree() == 0) out << abs(c);
			}

			if (it->degree() != 0)
				if (it->degree() == 1)
					out << "x";
				else
					out << "x^" << it->degree();
		}
		out << endl;
	}

private:
	list<Monomial<NumberType> > term_list; //sorted by decreasing degrees
	int number_of_terms;
	int highest_degree;

	// KLR REMIND STUDENTS OF THIS ONE
	NumberType power(NumberType x, int n) const {
		NumberType product = 1;
		for (int i = 0; i < n; i++) {
			product *= x;
		}
		return product;
	}

	//private helper member function
	void insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m) {
		int m_degree = m.degree();

		auto itr1 = p.term_list.begin();
		Monomial<NumberType> first_m = *itr1;
		// if the first element in the list has a coefficient and
		//		degree 0 then pop that element and push the 
		//		monomial sent to function
		if (first_m.coefficient() == 0 && first_m.degree() == 0) {
			//if (p == Polynomial<NumberType>::ZERO) {
			p.term_list.pop_front(); //get rid of (0, 0) term
			p.term_list.push_front(m);

			p.highest_degree = m.degree();
			p.number_of_terms = 1;
			return;
		}
		if (p.number_of_terms == 0 && p.highest_degree == 0) { //no terms yet
			p.term_list.push_front(m);
			p.highest_degree = m.degree();
			p.number_of_terms = 1;
			return;
		}
		else { // other monomials in the list
			auto itr = p.term_list.begin();
			while (itr != p.term_list.end()) {
				Monomial<NumberType> current_m = *itr;
				if (current_m.degree() == m_degree) { //equal exponents

					if ((current_m.coefficient() + m.coefficient()) == 0) {
						// coefficient for this term has gone to 0
						// remove term and push 0,0 term
						itr = p.term_list.erase(itr); //returns itr pointing to next elem
						p.number_of_terms--;
						if (p.number_of_terms == 0) {
							p.highest_degree = 0;
							p.term_list.push_back(Monomial<NumberType>(0, 0));
						}
						else {
							// update highest_degree from current itr
							//	returned from previous erase
							if (p.highest_degree == m_degree) {
								p.highest_degree = (*itr).degree();
							}
						}
					}
					else {
						//update coefficient for this term with equal expo
						(*itr).assign_coefficient(current_m.coefficient() + m.coefficient());
					}
					return;
				} // monomial needs to be inserted in front of current_m
				else if (current_m.degree() < m_degree) {
					// insert m before current_m
					auto itr_m = p.term_list.insert(itr, m);
					p.number_of_terms++;
					if (p.highest_degree == current_m.degree()) {
						p.highest_degree = (*itr_m).degree();
					}
					return;
				} // current_m.degree > m_degree 
				  // monomial needs to be inserted somewhere after current_m
				else {
					itr++;
					// reached end of list insert
					if (itr == p.term_list.end()) {
						p.term_list.push_back(m);
						p.number_of_terms++;
						return;
					}

				}
			}

		}
	}
};

template<typename NumberType>
istream& operator>>(istream& in, Polynomial<NumberType>& rhs) {
	rhs.read();
	return in;
}

template<typename NumberType>
ostream& operator<<(ostream& out, const  Polynomial<NumberType>& rhs) {
	rhs.print();
	return out;
}
#endif

