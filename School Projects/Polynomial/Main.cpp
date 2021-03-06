#include <string>
#include "polynomial.h"

using namespace std;
template<typename NumberType>
void Polynomial<typename NumberType>::print(ostream& out) const {
	const auto tlist = this->term_list;

	for (auto it = tlist.begin(); it != tlist.end(); it++) {
		if (it == tlist.begin()) {
			if ();
			out << (*it).coefficient();
		}
		else {
			if ((*it).coefficient() < 0) {
				out << " - ";
			}
			else {
				out << " + ";
			}

			if (abs((*it).coefficient()) != 1) {
				out << (*it).coefficient();
			}
		}

		if ((*it).degree() > 1) {
			out << "x^" << (*it).degree();
		}
		else if ((*it).degree() == 1) {
			out << "x";
		}
	}
}

template<typename NumberType>
void Polynomial<typename NumberType>::read(istream& in) {
	int c;
	int d;

	cout << "Enter a polynomial ";
	//insert_in_poly(poly, mon);

	while (true) {
		in >> c;
		if (c == 0) {
			break;
		}
		in >> d;
		if (d < 0) {
			break;
		}

		cout << c << endl;
		cout << d << endl;

		insert_in_poly(*this, Monomial<int>(c, d));
	}
}

template<typename NumberType>
void Polynomial<typename NumberType>::insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m) {
	// check p to determine if the term list is empty
	//		number_of_terms and highest_degree will be 0
	//		simply add m to the term_list
	auto& tlist = p.term_list;
	auto& hdegree = p.highest_degree;
	int& numterms = p.number_of_terms;
	NumberType coef;

	if (hdegree == 0) {
		tlist.clear();
		tlist.push_back(m);
		hdegree = m.degree();
	}
	else {
		// if there are monomials in the list then iterate through the list
		//	to figure out where to insert the new monomial
		for (auto it = tlist.begin(); it != tlist.end(); it++) {
			// the degree of the monomial matches the degree of a monomial in the list
			//		add the coefficients
			//			if the coefficient goes to 0
			//				you need to handle this case
			//			otherwise update the coefficient for the monomial in the list
			if ((*it).degree() == m.degree()) {
				coef = (*it).coefficient() + m.coefficient();
				if (coef == 0) {
					tlist.remove(*it);
					numterms--;
					break;
				}
				else {
					(*it).assign_coefficient(coef);
					break;
				}
			}
			else if (m.degree() > (*it).degree()) {

				tlist.insert(it, m);
				if (m.degree() > p.gethighestdegree()) {
					hdegree = m.degree();
				}
				numterms++;
				break;
			}
			else {
				tlist.push_back(m);
				break;
			}
		}
	}
}

int main() {
	
	Polynomial<int> poly;

	cin >> poly;

	cout << poly;
}

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


