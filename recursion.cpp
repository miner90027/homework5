/* Aleks McCormick
 * UAF CS 202
 * Homework 5
 * PROGRAM NAME: Recursion
 * 04/24/2021
 */
#include <iostream>
#include "StopWatch.hpp"
int fib(int n);
int fib_loop(int n);


int main() {
	std::cout << fib(15) << std::endl;
	return 0;
}

int fib(int n){
	if(n == 0) return n;
	if(n == 1) return n;
	return (fib(n-1) + fib(n-2));
}

int fib_loop(int n){
	return n;
}
