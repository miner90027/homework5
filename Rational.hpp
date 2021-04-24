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
class Rational {
   friend std::ostream& operator<<(std::ostream &, const Rational &rhs);
   friend Rational operator+(const Rational &lhs, const Rational &rhs);
   friend Rational operator-(const Rational &lhs);
   friend bool operator==(const Rational &lhs, const Rational &rhs);
   friend bool operator<(const Rational &lhs, const Rational &rhs);

public:
   Rational(int,int=1); //NOLINT(google-explicit-constructor): Allow implicit conversion from int
   Rational & operator+=(const Rational& rhs);
   Rational & operator-=(const Rational& rhs);
   Rational & operator*=(const Rational& rhs);
   Rational & operator/=(const Rational& rhs);
   Rational & operator++();        //prefix ++
   Rational operator++(int); //postfix ++
   Rational & operator--();        //prefix --
   Rational operator--(int); //postfix --
private:
   void reduce();

   int _numerator;
   int _denominator;
};

Rational operator-(const Rational &lhs, const Rational &rhs);
Rational operator*(Rational lhs, const Rational &rhs);
Rational operator/(Rational lhs, const Rational &rhs);

bool operator!=(const Rational &lhs, const Rational &rhs);
bool operator>(const Rational &lhs, const Rational &rhs);
bool operator<=(const Rational &lhs, const Rational &rhs);
bool operator>=(const Rational &lhs, const Rational &rhs);


Rational::Rational(int num, int den) : _numerator(num), _denominator(den) {
	reduce();
}

std::ostream &operator<<(std::ostream &os, const Rational &rhs) {
	os << rhs._numerator;
	if (rhs._denominator != 1)
		os << "/" << rhs._denominator;
	return os;
}

Rational operator+(const Rational &lhs, const Rational &rhs) { //canonical
	auto temp{lhs};
	temp += rhs;
	return temp;
}

Rational & Rational::operator+=(const Rational &rhs) {
	// a/b + c/d = (ad+bc)/ad
	_numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
	_denominator *= rhs._denominator;
	reduce();
	return *this;
}

void Rational::reduce() {
	auto gcd = std::gcd(_numerator,_denominator);
	_numerator /= gcd;
	_denominator /= gcd;
	if (_denominator < 0) {
		_numerator *= -1;
		_denominator *= -1;
	}
}

Rational operator-(const Rational &lhs) {
	return { -lhs._numerator, lhs._denominator };
}

Rational &Rational::operator-=(const Rational &rhs) { //Canonical
	*this = *this - rhs; //uses Rational::operator- to define operator-=
	return *this;
}

Rational &Rational::operator*=(const Rational &rhs) {
	_numerator *= rhs._numerator;
	_denominator *= rhs._denominator;
	return *this;
}

Rational &Rational::operator/=(const Rational &rhs) {
	return *this *= {rhs._denominator,rhs._numerator};
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
	return lhs + -rhs;
}

// pass lhs by value because we were going to copy it anyway
Rational operator*(Rational lhs, const Rational &rhs) { //Canonical
	return lhs *= rhs;
}

// pass lhs by value because we were going to copy it anyway
Rational operator/(Rational lhs, const Rational &rhs) { //Canonical
	return lhs /= rhs;
}

Rational & Rational::operator++() {//prefix ++
	return *this += 1;
}

Rational Rational::operator++(int) {//postfix ++
	auto copy{*this};
	++(*this);
	return copy;
}

Rational & Rational::operator--() {//prefix --
	return *this -= 1;
}

Rational Rational::operator--(int) {//postfix --
	auto copy{*this};
	--(*this);
	return copy;
}

bool operator==(const Rational &lhs, const Rational &rhs) {
	return lhs._numerator==rhs._numerator && lhs._denominator==rhs._denominator;
}

bool operator<(const Rational &lhs, const Rational &rhs) {
	return lhs._numerator*rhs._denominator < rhs._numerator*lhs._denominator;
}

bool operator!=(const Rational &lhs, const Rational &rhs) {//canonical
	return !(rhs==lhs);
}

bool operator>(const Rational &lhs, const Rational &rhs) {//canonical
	return rhs<lhs;
}

bool operator<=(const Rational &lhs, const Rational &rhs) {//canonical
	return ! (rhs>lhs);
}

bool operator>=(const Rational &lhs, const Rational &rhs) {//canonical
	return ! (rhs<lhs);
}

#endif//CS202CLASSEXAMPLE_RATIONAL_HPP
