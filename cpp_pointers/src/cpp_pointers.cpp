//============================================================================
// Name        : cpp_pointers.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int addition(int a, int b)
{
	return(a+b);
}

int subtraction(int a, int b)
{
	return(a-b);
}

int operation(int x, int y, int (*functocall)(int, int))
{
	int g;

	g = (*functocall)(x,y);

	return g;
}

void function_1()
{
	cout << "in function 1 now"<< endl;
}

void function_2()
{
	cout << "in function 2 now"<< endl;
}

void function_3()
{
	cout << "in function 3 now"<< endl;
}

int a[] = {1, 2, 3};

void (*Array[])()  = {
		function_1,
		function_2,
		function_3
};


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int array[5] = { 10, 20, 30, 40, 50};

	int *ptr = array;

	cout << "*ptr++ : " << *ptr++ << endl;

	cout << "*++ptr : " << *++ptr << endl;

	cout << "++*ptr : " << ++*ptr << endl;

	cout << "(*ptr)++ : " << (*ptr)++ << endl;

	cout << "*ptr : " << *ptr<< endl;

	int m, n;

	m = operation ( 7, 8, addition );
	n = operation ( m, 5, subtraction );

	cout<< "m: "<< m << "\t" << "n: " << n << endl;

	for(int i=0; i<3; i++)
	{
		(*Array[i])();
	}


	  int myarray[3] = {10,20,30};


	  for (int &elem : myarray)
	    elem++;

	  for (int i=0; i<3; ++i)
	    cout << myarray[i] << " ";

	  cout << endl;

	return 0;
}
