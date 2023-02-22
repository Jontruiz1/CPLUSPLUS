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
<<<<<<< Updated upstream
	Monomial<NumT>(NumT c = 0, int d = 0) : coeff(c), expo(d){ };
=======
	Monomial<NumT>(NumT c = 0, int d = 0) : coeff(c), expo(d) { };
>>>>>>> Stashed changes
	NumT coefficient(void) const { return coeff; };
	int degree(void) const { return expo; };
	void assign_coefficient(const NumT c) { coeff = c; };
	void assign_degree(const int d) { expo = d; };

	bool operator==(const Monomial<NumT>& m) const {
		return (coeff == m.coeff && expo == m.expo);
	}

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

	template <typename NumberType>
	const Polynomial<NumberType>& operator=(const Polynomial<NumberType>& rhs) {

		term_list = rhs.term_list;
		number_of_terms = rhs.number_of_terms;
		highest_degree = rhs.highest_degree;
	} // copy assignment


	const Polynomial<NumberType>& operator=(Polynomial<NumberType>&& rhs);// move assignment

	// ADDITION																			
	Polynomial<NumberType> operator+=(const Monomial<NumberType>& m);
	Polynomial<NumberType> operator+=(const Polynomial<NumberType>& rhs);

	template <typename NumberType>
	const Polynomial<NumberType> operator+(const Monomial<NumberType>& m)const {
		Polynomial<NumberType> temp = *this;
		temp += m;
		return temp;
	}

	template <typename NumberType>
	const Polynomial<NumberType> operator+(const Polynomial<NumberType>& rhs) const {
		Polynomial<NumberType> temp = *this;
		temp += rhs;
		return temp;
	}
>>>>>>> Stashed changes

	// SUBTRACTION
	Polynomial<NumberType> operator-=(const Monomial<NumberType>& m);
	Polynomial<NumberType> operator-=(const Polynomial<NumberType>& rhs);
<<<<<<< Updated upstream
	const Polynomial<NumberType> operator- (const Monomial<NumberType>& m)const;
	const Polynomial<NumberType> operator- (const Polynomial<NumberType>& rhs) const;

	// MULTIPLICATION
	Polynomial<NumberType> operator*=(const Monomial<NumberType>& m);
	Polynomial<NumberType> operator*=(const Polynomial<NumberType>& rhs);
	const Polynomial<NumberType> operator*(const Monomial<NumberType>& m) const;
	const Polynomial<NumberType> operator*(const Polynomial<NumberType>& rhs)const;

=======
	template <typename NumberType>
	const Polynomial<NumberType> operator-(const Monomial<NumberType>& m)const {
		Polynomial<NumberType> temp = *this;
		temp -= m;
		return temp;
	}

	template <typename NumberType>
	const Polynomial<NumberType> operator-(const Polynomial<NumberType>& rhs) const {
		Polynomial<NumberType> temp = *this;
		temp -= rhs;
		return temp;
	}
	// MULTIPLICATION
	Polynomial<NumberType> operator*=(const Monomial<NumberType>& m) {
	}
	Polynomial<NumberType> operator*=(const Polynomial<NumberType>& rhs) {
		//(5x^5 + 3x^4 - 2x^2)(3x^2) = 15x^7 + 9x^6 + 6x^4

	}
	template <typename NumberType>
	const Polynomial<NumberType> operator*(const Monomial<NumberType>& m) const {
		Polynomial<NumberType> temp = *this;
		temp *= m;
		return temp;
	}

	template <typename NumberType>
	const Polynomial<NumberType> operator*(const Polynomial<NumberType>& rhs)const {
		Polynomial<NumberType> temp = *this;
		temp *= rhs;
		return temp;
	}
>>>>>>> Stashed changes
	// EVALUATION POLYNOMIAL
	const NumberType evaluate(NumberType x) const;

	// EQUALITY TESTS
<<<<<<< Updated upstream
	bool operator==(const Polynomial<NumberType>& p) const;
=======
	bool operator==(const Polynomial<NumberType>& p) const {

		
	}

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
			insert_in_poly(*this, Monomial<NumberType>(c, d));
=======
			insert_in_poly(*this, Monomial<NumberType>(c, d) );
>>>>>>> Stashed changes
			in >> c;
		}

	}

	// print() function -- make sure you look back at requirements for this
	void print(ostream& out = cout) const {
		for (auto it = term_list.begin(); it != term_list.end(); ++it) {
<<<<<<< Updated upstream
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
=======
			auto c = it->coefficient();
			auto d = it->degree();


			if (d == 0) {
				if (it == term_list.begin()) {
					cout << 1;
				}
				else {
					cout << " + " << 1;
				}
				continue;
>>>>>>> Stashed changes
			}
			cout << ( it == term_list.begin() ? (c < 0 ? "-" : "") : (c < 0 ? " - " : " + "));

<<<<<<< Updated upstream

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
=======
			if (abs(c) != 1) {
				cout << abs(c);
			}
			cout << "x";
			if (d > 1) {
				cout << "^" << d;
			}
		}
	}

private:
	list<Monomial<NumberType> > term_list; //SORTED BY DECREASING DEGREES
	int number_of_terms;
	int highest_degree;

	//private helper member function -- review notes below function prototype
	void insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m) {
		/*
		check p to determine if the term list is empty
			-	number_of_terms and highest_degree will be 0
			-	simply add m to the term_list
		*/

		if (p.highest_degree == 0) {
			if (p.number_of_terms == 1) {
				p.term_list.pop_front();
			}
			p.term_list.push_back(m);
			p.number_of_terms = 1;
			p.highest_degree = m.degree();
		}
		else {
			/*
			if there are monomials in the list then iterate through the list
				to figure out where to insert the new monomial
				*/
			for (auto it = p.term_list.begin(); it != p.term_list.end(); ++it) {
				auto currC = it->coefficient();
				auto currD = it->degree();
				/*
				3 cases:
				-the degree of the monomial matches the degree of a monomial in the list
					- add the coefficients
					- if the coefficient goes to 0, you need to handle this case
					-otherwise update the coefficient for the monomial in the list
					*/
				if (currD == m.degree()) {
					auto added = currD + m.coefficient();
					if (added == 0) {
						p.term_list.erase(it);
						p.number_of_terms--;
						if (number_of_terms == 0) {
							p.term_list.push_back(Monomial<NumberType>(0, 0));
						}
						p.highest_degree = p.term_list.begin()->degree();
						
					}
					else {
						it->assign_coefficient(added);
					}
					break;
				}
				/*
			-	monomial gets added before another monomial in the term_list
				-	update number_of_terms and possibly highest_degree */
				else if (m.degree() > currD) {
					p.term_list.insert(it, m);
					number_of_terms++;
					if (highest_degree < m.degree()) {
						p.highest_degree = currD;
					}
					break;
				}
				/*
				- monomial gets added to the end of the term list
					- update number_of_terms
					*/
				else {
					p.term_list.push_back(m);
					number_of_terms++;
					break;
				}
			}
		}
	}
>>>>>>> Stashed changes
	
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
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
#endif