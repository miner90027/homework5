//
// Originaly Created by Chris Hartman on 2/18/21.
//
/* Aleks McCormick
 * UAF CS 202
 * Homework 5
 * PROGRAM NAME: Template Rational class
 * 04/24/2021
 */

#ifndef CS202CLASSEXAMPLE_RATIONAL_HPP
#define CS202CLASSEXAMPLE_RATIONAL_HPP
#include <iostream>
#include <numeric>

// class invariant:
// _denominator is always > 0

template<typename Num, typename Den>
class Rational {

	template<typename L, typename R>
   friend std::ostream& operator<<(std::ostream &, const Rational<L,R> &rhs);

    template<typename L, typename R>
   friend Rational operator+(const Rational<L,R> &lhs, const Rational<L,R> &rhs);
	template<typename L, typename R>
   friend Rational operator-(const Rational<L,R> &lhs);
	template<typename L, typename R>
   friend bool operator==(const Rational<L,R> &lhs, const Rational<L,R> &rhs);
	template<typename L, typename R>
   friend bool operator<(const Rational<L,R> &lhs, const Rational<L,R> &rhs);

public:
   Rational(Num,Den = 1); //NOLINT(google-explicit-constructor): Allow implicit conversion from int
   Rational & operator+=(const Rational<Num,Den>& rhs);
   Rational & operator-=(const Rational<Num,Den>& rhs);
   Rational & operator*=(const Rational<Num,Den>& rhs);
   Rational & operator/=(const Rational<Num,Den>& rhs);
   Rational & operator++();        //prefix ++
   Rational operator++(int); //postfix ++
   Rational & operator--();        //prefix --
   Rational operator--(int); //postfix --
private:
   void reduce();

   int _numerator;
   int _denominator;
};

template<typename Num, typename Den>
Rational<Num,Den> operator-(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs);
template<typename Num, typename Den>
Rational<Num,Den> operator*(Rational<Num,Den> lhs, const Rational<Num,Den> &rhs);
template<typename Num, typename Den>
Rational<Num,Den> operator/(Rational<Num,Den> lhs, const Rational<Num,Den> &rhs);

template<typename Num, typename Den>
bool operator!=(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs);
template<typename Num, typename Den>
bool operator>(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs);
template<typename Num, typename Den>
bool operator<=(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs);
template<typename Num, typename Den>
bool operator>=(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs);

template<typename Num, typename Den>
Rational<Num,Den>::Rational(Num num, Den den) : _numerator(num), _denominator(den) {
	reduce();
}

template<typename L, typename R>
std::ostream &operator<<(std::ostream &os, const Rational<L,R> &rhs) {
	os << rhs._numerator;
	if (rhs._denominator != 1)
		os << "/" << rhs._denominator;
	return os;
}

template<typename Num, typename Den>
Rational<Num,Den> operator+(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs) { //canonical
	auto temp{lhs};
	temp += rhs;
	return temp;
}

template<typename Num, typename Den>
Rational<Num,Den> & Rational<Num,Den>::operator+=(const Rational<Num,Den> &rhs) {
	// a/b + c/d = (ad+bc)/ad
	_numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
	_denominator *= rhs._denominator;
	reduce();
	return *this;
}

template<typename Num, typename Den>
void Rational<Num,Den>::reduce() {
	auto gcd = std::gcd(_numerator,_denominator);
	_numerator /= gcd;
	_denominator /= gcd;
	if (_denominator < 0) {
		_numerator *= -1;
		_denominator *= -1;
	}
}

template<typename Num, typename Den>
Rational<Num,Den> operator-(const Rational<Num,Den> &lhs) {
	return { -lhs._numerator, lhs._denominator };
}

template<typename Num, typename Den>
Rational<Num,Den> &Rational<Num,Den>::operator-=(const Rational<Num,Den> &rhs) { //Canonical
	*this = *this - rhs; //uses Rational::operator- to define operator-=
	return *this;
}

template<typename Num, typename Den>
Rational<Num,Den> &Rational<Num,Den>::operator*=(const Rational<Num,Den> &rhs) {
	_numerator *= rhs._numerator;
	_denominator *= rhs._denominator;
	return *this;
}

template<typename Num, typename Den>
Rational<Num,Den> &Rational<Num,Den>::operator/=(const Rational<Num,Den> &rhs) {
	return *this *= {rhs._denominator,rhs._numerator};
}

template<typename Num, typename Den>
Rational<Num,Den> operator-(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs) {
	return lhs + -rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename Num, typename Den>
Rational<Num,Den> operator*(Rational<Num,Den> lhs, const Rational<Num,Den> &rhs) { //Canonical
	return lhs *= rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename Num, typename Den>
Rational<Num,Den> operator/(Rational<Num,Den> lhs, const Rational<Num,Den> &rhs) { //Canonical
	return lhs /= rhs;
}

template<typename Num, typename Den>
Rational<Num,Den> & Rational<Num,Den>::operator++() {//prefix ++
	return *this += 1;
}

template<typename Num, typename Den>
Rational<Num,Den> Rational<Num,Den>::operator++(int) {//postfix ++
	auto copy{*this};
	++(*this);
	return copy;
}

template<typename Num, typename Den>
Rational<Num,Den> & Rational<Num,Den>::operator--() {//prefix --
	return *this -= 1;
}

template<typename Num, typename Den>
Rational<Num,Den> Rational<Num,Den>::operator--(int) {//postfix --
	auto copy{*this};
	--(*this);
	return copy;
}

template<typename Num, typename Den>
bool operator==(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs) {
	return lhs._numerator==rhs._numerator && lhs._denominator==rhs._denominator;
}

template<typename Num, typename Den>
bool operator<(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs) {
	return lhs._numerator*rhs._denominator < rhs._numerator*lhs._denominator;
}

template<typename Num, typename Den>
bool operator!=(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs) {//canonical
	return !(rhs==lhs);
}

template<typename Num, typename Den>
bool operator>(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs) {//canonical
	return rhs<lhs;
}

template<typename Num, typename Den>
bool operator<=(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs) {//canonical
	return ! (rhs>lhs);
}

template<typename Num, typename Den>
bool operator>=(const Rational<Num,Den> &lhs, const Rational<Num,Den> &rhs) {//canonical
	return ! (rhs<lhs);
}

#endif//CS202CLASSEXAMPLE_RATIONAL_HPP
