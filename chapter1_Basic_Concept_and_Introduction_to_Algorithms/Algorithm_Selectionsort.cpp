/*
Algorithm:Selectionsort
input: An array A[1...n] of n elements
output: A[1..n] sorted in nondereasing order
author:Maisui_Y
time:2018.09.26
*/
#include<iostream>
using namespace std;
float selection(float A[], int n);
int main()
{
	float A[10] = { 1,9,4,3,12,98,2,4,2,0.3 };
	float R;
	R = selection(A, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}
float selection(float A[], int n)
{
	int k;  //record the i-th small element
	int i, j;
	float temp;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (A[j] < A[k])
				k = j;
		if (abs(k - i) > 0.001)
		{
			temp = A[i];
			A[i] = A[k];
			A[k] = temp;
		}
	}
	return 0;
}