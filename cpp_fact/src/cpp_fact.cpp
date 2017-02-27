//============================================================================
// Name        : cpp_fact.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int n;

	cout << " enter a number "<< endl;

	cin >> n;

	cout << "Factorial of " << n <<" is "<< factorial(n) << endl;

	return 0;
}
