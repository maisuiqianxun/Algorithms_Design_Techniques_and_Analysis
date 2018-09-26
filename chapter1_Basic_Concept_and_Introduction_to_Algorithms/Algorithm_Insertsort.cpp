/*
Algorithm:Insertionsort
input: An array A[1...n] of n elements
output: A[1..n] sorted in nondereasing order
author:Maisui_Y
time:2018.09.26
*/
#include<iostream>
using namespace std;
float Insertionsort(float A[], int n);
int main()
{
	float A[10] = { 1,9,4,3,12,98,2,4,2,0.3 };
	float R;
	R = Insertionsort(A, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}
float Insertionsort(float A[], int n)
{
	int i,j;
	float x;
	for (i = 1; i < n; i++)
	{
		x = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
	return 0.0f;
}
