#include "Polynomial.h"

template <typename NumberType>
const Polynomial<NumberType>& Polynomial<NumberType>::operator=(const Polynomial<NumberType>& rhs) {

	term_list = rhs.term_list;
	number_of_terms = rhs.number_of_terms;
	highest_degree = rhs.highest_degree;
}

template <typename NumberType>
const Polynomial<NumberType>& Polynomial<NumberType>::operator=(const Polynomial<NumberType>&& rhs);//R-val reference		    //assignment operators +- and use member function binary op + for this class

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator+=(const Monomial<NumberType>& m);

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator+=(const Polynomial<NumberType>& rhs);

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator+ (const Monomial<NumberType>& m)const {
	Polynomial<NumberType> temp = *this;
	temp += m;
	return temp;
}

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator+ (const Polynomial<NumberType>& rhs) const {
	Polynomial<NumberType> temp = *this;
	temp += rhs;
	return temp;
}

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator-=(const Monomial<NumberType>& m);

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator-=(const Polynomial<NumberType>& rhs);

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator- (const Monomial<NumberType>& m)const {
	Polynomial<NumberType> temp = *this;
	temp -= m;
	return temp;
}

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator- (const Polynomial<NumberType>& rhs) const {
	Polynomial<NumberType> temp = *this;
	temp -= rhs;
	return temp;
}

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator*=(const Monomial<NumberType>& m);

template <typename NumberType>
Polynomial<NumberType> Polynomial<NumberType>::operator*=(const Polynomial<NumberType>& rhs);

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator*(const Monomial<NumberType>& m) const {
	Polynomial<NumberType> temp = *this;
	temp *= m;
	return temp;
}

template <typename NumberType>
const Polynomial<NumberType> Polynomial<NumberType>::operator*(const Polynomial<NumberType>& rhs)const {
	Polynomial<NumberType> temp = *this;
	temp *= rhs;
	return temp;
}

template <typename NumberType>
const NumberType Polynomial<NumberType>::evaluate(NumberType x) const;

template <typename NumberType>
bool Polynomial<NumberType>::operator==(const Polynomial<NumberType>& p) const;

template <typename NumberType>
bool Polynomial<NumberType>::operator!=(const Polynomial<NumberType>& p) const;

template <typename NumberType>
void Polynomial<NumberType>::insert_in_poly(Polynomial<NumberType>& p, const Monomial<NumberType>& m);

template <typename NumberType>
NumberType Polynomial<NumberType>::power(NumberType x, int n) const;
