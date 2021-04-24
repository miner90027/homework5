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
	std::cout << fib(5) << std::endl;
	std::cout << fib_loop(5) << std::endl;
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
