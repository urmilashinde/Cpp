//============================================================================
// Name        : cpp_merge_sort.cpp
// Author      : Urmila Shinde
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//merge_sort(A, start, end)
//{
//	if start < end
//		mid = (start+end)/2;
//
//		merge_sort( A, start, mid);
//		merge_sort(A, mid+1, end);
//
//		merge(A, start, mid, end);
//}

void merge(int* A, int start, int mid, int end)
{
	int i, j;
	vector<int> temp;

	int k = start;
	i = start;
	j = mid+1;

	while((i<=mid) && (j<=end))
	{

		if(A[i] < A[j])
		{
			temp.push_back(A[i]);
			i++;
		}
		else
		{
			temp.push_back(A[j]);
			j++;
		}

	}

	if(i > mid)
	{
		while(j <= end)
		{
			temp.push_back(A[j]);
			j++;
		}
	}

	if(j > end)
	{
		while(i <= mid)
		{
			temp.push_back(A[i]);
			i++;
		}
	}

	for(int num : temp)
	{
		A[k] = num;
		k++;
	}

}

void merge_sort(int* A, int start, int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;

		merge_sort(A, start, mid);
		merge_sort(A, mid+1, end);

		merge(A, start, mid, end);
	}

}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int Array[] = {17, 12, 6, 19, 23, 8, 5, 10 };

	merge_sort(Array, 0, 7);

	for(int i = 0; i<=7; i++)
	{
		cout<< Array[i] << " ";
	}

	return 0;
}
