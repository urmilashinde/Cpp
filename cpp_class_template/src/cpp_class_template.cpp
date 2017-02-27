//============================================================================
// Name        : cpp_class_template.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

template <class T>
class Mypairs{
	T x, y;
public:
	Mypairs(T num1, T num2)
	{
		x = num1;
		y = num2;
	}
	T getmax();

};

/*
template <class T>
Mypairs<T> :: Mypairs(T num1, T num2)
{
	x = num1;
	y = num2;
}
*/
template <class T>
T Mypairs<T> :: getmax()
{
	T retval;

	retval = x>y ? x : y;

	return retval;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Mypairs<int> obj1(25, 30);

	Mypairs<float>obj2(4.56, 4.32);

	Mypairs<char>obj3('A', 'a');


	cout<<"max for obj1 is: " << obj1.getmax() << endl;

	cout<<"max for obj2 is: " << obj2.getmax() << endl;

	cout<<"max for obj3 is: " << obj3.getmax() << endl;

	return 0;
}
