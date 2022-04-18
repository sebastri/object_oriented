//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'
int maxOfTwo(int a, int b) {
if (a > b) {
    cout << "A is greater than B\n";
    return a;
} else {
    cout << "B is greater than or equal to A\n";
    return b;
}
}

int fibonacci(int n) {
	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:\n";
	for (int x = 1; x < n+1; ++x) {
		cout << (x) << ":" << (b) << '\n';
		int temp = b;
		b += a; 
		a = temp;
	}
	cout << "----\n";
	return b;
}

int squareNumberSum(int n) {
	int totalSum = 0;
	for (int i = 1; i < n + 1; ++i) {
		totalSum= totalSum + i*i;
		cout << i*i << '\n';
	}
	return totalSum;
}

int triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":";
	while (acc < n) {
	cout << acc << " ";
	acc += num;
	num += 1;
	}
	cout << "\n";
	return 0;
}

int isPrime(int n) {
	bool primeness = true;
	for (int i=2; i<n; i = ++i) {
		if (n % i == 0) {
		primeness = false;
		}
	}
	return primeness;
}	

int naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n; ++number){
		if (isPrime(number) == true){
			cout << number << " is a prime\n";
		}
	}
	return 0;
}

int findGreatestDivisor(int n) {
	for (int divisor = n-1; divisor>-1 ; --divisor){
		if (n % divisor == 0) {
			return divisor;
		}
	}
}

// C++ programs start by executing the function main
int main()
{
	cout << "Oppgave a)\n";
	cout << maxOfTwo(5, 6) << '\n';

	cout << "Oppgave c)\n";
	cout << fibonacci(7) << '\n';

	cout << "Oppgave d)\n";
	cout << squareNumberSum(3) << '\n';

	cout << "Oppgave e)\n";
	cout << triangleNumbersBelow(5) << '\n';

	cout << "Oppgave f)\n";
	cout << isPrime(5) << '\n';

	cout << "Oppgave g)\n";
	cout << naivePrimeNumberSearch(5) << '\n';

	cout << "Oppgave h)\n";
	cout << findGreatestDivisor(6) << '\n';



	keep_window_open();
}

//------------------------------------------------------------------------------
