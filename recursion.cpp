/* Aleks McCormick
 * UAF CS 202
 * Homework 5
 * PROGRAM NAME: Recursion
 * 04/24/2021
 */
#include <iostream>
#include "StopWatch.hpp"
using std::cout;
using std::endl;

int fib(int n);
int fib_loop(int n);
unsigned long ack(unsigned long m, unsigned long n);

int main() {
	int n = 5;
	unsigned long a = 4;
	unsigned long b = 0;

	StopWatch timer;
	cout << "fib(" << n << ") = " << fib(n) << endl;
	timer.stop();
	cout << "Calculated the " << n << "th number of the Fibonacci Sequence using recursion in " << timer.getTimeMilli() <<" milli-seconds." << endl;

	timer.start();
	cout << "fib_loop(" << n << ") = " << fib_loop(n) << endl;
	timer.stop();
	cout << "Calculated the " << n << "th number of the Fibonacci Sequence using iteration in " << timer.getTimeMilli() <<" milli-seconds." << endl;

	timer.start();
	cout << "ack("<<a<<","<<b<<") = " << ack(a, b) << endl;
	timer.stop();
	cout << "Calculated the Ackermann's number using the inputs ("<< a << ", "<< b << ") in " << timer.getTimeMilli() <<" milli-seconds." << endl;

	return 0;
}

int fib(int n){
	if(n <= 1) return n;
	return (fib(n-1) + fib(n-2));
}

int fib_loop(int n){
	int sum = 0;
	int n1 = 0;
	int n2 = 1;

	for(int i = 2; i <= n; i++){
		sum = n1 + n2;
		n1 = n2;
		n2 = sum;
	}
	return sum;
}

unsigned long ack(unsigned long m, unsigned long n){
	if(m == 0)
		return n+1;
	else if(m > 0 && n == 0)
		return ack(m-1,1);
	else
		return ack(m -1,ack(m,n-1));
}