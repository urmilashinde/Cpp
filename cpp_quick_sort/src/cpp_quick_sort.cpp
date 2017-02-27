//============================================================================
// Name        : cpp_quick_sort.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// O(n^2) : worst case
// O(n log n) : average
// memory: no additional== in place

void swap (int &x, int &y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

int Partition(int* A, int start, int end)
{
	int p = A[end];

	int i = start - 1;
	int j = end + 1;

	while(1)
	{
		do{
			i++;
		}
		while(A[i] <= p);

		do{
			j--;
		}
		while(A[j] > p);


		if(i<j)
		{
			swap (A[i], A[j]);
		}
		else
		{
			return j;
		}

	}

}

void quick_sort(int* A, int start, int end)
{
	if((start == end) || (end < start))
	{
		return;
	}

	int p = Partition(A, start, end);

	quick_sort(A, start, p);
	quick_sort(A, p+1, end);
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int Array[] = {17, 12, 6, 19, 23, 8, 5, 10 };

	quick_sort(Array, 0, 7);

	for(int i = 0; i<=7; i++)
	{
		cout<< Array[i] << " ";
	}

	return 0;
}
