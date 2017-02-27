//============================================================================
// Name        : Cpp_Exception.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
using namespace std;

float division( float a, float b)
{
	if(b == 0)
	{
		throw logic_error("B cannot be zero");
	}

	return a/b;

}

float division2( float a, float b)
{
	int result = 0;

	try{
		if( b == 0)
		{
			throw 30;
		}
	}
	catch(int e)
	{
		cout<<endl;
		cout<<" ==== divide by zero exception has occurred ====="<<endl;
	}

	result = a/b;

	return result;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	try
	{
		float a, b;
		cout<<"Enter dividend"<<endl;
		cin>> a ;
		cout<<"Enter divisor"<<endl;
		cin>> b ;

		cout << "division of two numbers is " << division(a,b) << endl;
	}
	catch(exception& e)
	{
		cout << endl;
		cout<<"==== urmila exception====="<< e.what()<<endl;

	}
	catch(...)
	{
		cout<<"unknown exception caught"<<endl;
	}

	return 0;
}
