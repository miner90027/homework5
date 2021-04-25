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

template<typename Type>
class Rational {

	template<typename T>
   friend std::ostream& operator<<(std::ostream &, const Rational<T> &rhs);

    template<typename T>
   friend Rational operator+(const Rational<T> &lhs, const Rational<T> &rhs);
	template<typename T>
   friend Rational operator-(const Rational<T> &lhs);
	template<typename T>
   friend bool operator==(const Rational<T> &lhs, const Rational<T> &rhs);
	template<typename T>
   friend bool operator<(const Rational<T> &lhs, const Rational<T> &rhs);

public:
   Rational(Type num,Type den = 1); //NOLINT(google-explicit-constructor): Allow implicit conversion from int
   Rational & operator+=(const Rational<Type>& rhs);
   Rational & operator-=(const Rational<Type>& rhs);
   Rational & operator*=(const Rational<Type>& rhs);
   Rational & operator/=(const Rational<Type>& rhs);
   Rational & operator++();        //prefix ++
   const Rational operator++(int); //postfix ++
   Rational & operator--();        //prefix --
   const Rational operator--(int); //postfix --
private:
   void reduce();

   int _numerator;
   int _denominator;
};

template<typename Type>
Rational<Type> operator-(const Rational<Type> &lhs, const Rational<Type> &rhs);
template<typename Type>
Rational<Type> operator*(Rational<Type> lhs, const Rational<Type> &rhs);
template<typename Type>
Rational<Type> operator/(Rational<Type> lhs, const Rational<Type> &rhs);

template<typename Type>
bool operator!=(const Rational<Type> &lhs, const Rational<Type> &rhs);
template<typename Type>
bool operator>(const Rational<Type> &lhs, const Rational<Type> &rhs);
template<typename Type>
bool operator<=(const Rational<Type> &lhs, const Rational<Type> &rhs);
template<typename Type>
bool operator>=(const Rational<Type> &lhs, const Rational<Type> &rhs);

template<typename Type>
Rational<Type>::Rational(Type num, Type den) : _numerator(num), _denominator(den) {
	reduce();
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Rational<T> &rhs) {
	os << rhs._numerator;
	if (rhs._denominator != 1)
		os << "/" << rhs._denominator;
	return os;
}

template<typename Type>
Rational<Type> operator+(const Rational<Type> &lhs, const Rational<Type> &rhs) { //canonical
	auto temp{lhs};
	temp += rhs;
	return temp;
}

template<typename Type>
Rational<Type> & Rational<Type>::operator+=(const Rational<Type> &rhs) {
	// a/b + c/d = (ad+bc)/ad
	_numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
	_denominator *= rhs._denominator;
	reduce();
	return *this;
}

template<typename Type>
void Rational<Type>::reduce() {
	auto gcd = std::gcd(_numerator,_denominator);
	_numerator /= gcd;
	_denominator /= gcd;
	if (_denominator < 0) {
		_numerator *= -1;
		_denominator *= -1;
	}
}

template<typename Type>
Rational<Type> operator-(const Rational<Type> &lhs) {
	return { -lhs._numerator, lhs._denominator };
}

template<typename Type>
Rational<Type> &Rational<Type>::operator-=(const Rational<Type> &rhs) { //Canonical
	*this = *this - rhs; //uses Rational::operator- to define operator-=
	return *this;
}

template<typename Type>
Rational<Type> &Rational<Type>::operator*=(const Rational<Type> &rhs) {
	_numerator *= rhs._numerator;
	_denominator *= rhs._denominator;
	return *this;
}

template<typename Type>
Rational<Type> &Rational<Type>::operator/=(const Rational<Type> &rhs) {
	return *this *= {rhs._denominator,rhs._numerator};
}

template<typename Type>
Rational<Type> operator-(const Rational<Type> &lhs, const Rational<Type> &rhs) {
	return lhs + -rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename Type>
Rational<Type> operator*(Rational<Type> lhs, const Rational<Type> &rhs) { //Canonical
	return lhs *= rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename Type>
Rational<Type> operator/(Rational<Type> lhs, const Rational<Type> &rhs) { //Canonical
	return lhs /= rhs;
}

template<typename Type>
Rational<Type> & Rational<Type>::operator++() {//prefix ++
	return *this += 1;
}

template<typename Type>
const Rational<Type> Rational<Type>::operator++(int) {//postfix ++
	auto copy{*this};
	++(*this);
	return copy;
}

template<typename Type>
Rational<Type> & Rational<Type>::operator--() {//prefix --
	return *this -= 1;
}

template<typename Type>
const Rational<Type> Rational<Type>::operator--(int) {//postfix --
	auto copy{*this};
	--(*this);
	return copy;
}

template<typename Type>
bool operator==(const Rational<Type> &lhs, const Rational<Type> &rhs) {
	return lhs._numerator==rhs._numerator && lhs._denominator==rhs._denominator;
}

template<typename Type>
bool operator<(const Rational<Type> &lhs, const Rational<Type> &rhs) {
	return lhs._numerator*rhs._denominator < rhs._numerator*lhs._denominator;
}

template<typename Type>
bool operator!=(const Rational<Type> &lhs, const Rational<Type> &rhs) {//canonical
	return !(rhs==lhs);
}

template<typename Type>
bool operator>(const Rational<Type> &lhs, const Rational<Type> &rhs) {//canonical
	return rhs<lhs;
}

template<typename Type>
bool operator<=(const Rational<Type> &lhs, const Rational<Type> &rhs) {//canonical
	return ! (rhs>lhs);
}

template<typename Type>
bool operator>=(const Rational<Type> &lhs, const Rational<Type> &rhs) {//canonical
	return ! (rhs<lhs);
}

#endif//CS202CLASSEXAMPLE_RATIONAL_HPP
