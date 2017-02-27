//============================================================================
// Name        : Cpp_Operator_overload.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Num
{

	int x, y;

	public:
	Num(){};
	Num(int a, int b);
	Num operator*(const Num&);
	friend ostream& operator<<(ostream &os, const Num&);
};

Num :: Num(int a, int b)
{
	x = a;
	y = b;
}

Num Num :: operator*(const Num& num2)
{
	Num num3;

	num3.x = x * num2.x;
	num3.y = y * num2.y;

	return num3;
}

ostream& operator<<(ostream &os, const Num& num2)
{
	os << ".x = "<< num2.x << endl;
	os << ".y = "<< num2.y << endl;
	return os;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Num num1(4, 5);
	Num num2(7, 8);

	Num num3;

	num3 = num1 * num2;

//	cout<< "num3.x = "<< num3.x << endl;
//	cout<< "num3.y = "<< num3.y << endl;

	cout << num3 << endl;

	return 0;
}
