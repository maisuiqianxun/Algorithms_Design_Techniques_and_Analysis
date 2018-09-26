/*
Algorithm:Bottomupsort
input: An array A[1...n] of n elements¡£
output: A[1..n] sorted in nondecreasing order.
author:Maisui_Y
time:2018.09.26
*/
#include<iostream>
using namespace std;
float Merge(float A[], int p, int q, int r);
float Bottomupsort(float A[], int n);
int main()
{
	int Len = 18;
	float array[18] = { 3,8,4,6,5,1,3,5,2,4,6,8,10,23,43,12,3,45 };
	float mn;
	mn = Bottomupsort(array, Len);

	for (int ui = 0; ui < Len; ui++)
	{
		cout << array[ui] << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}
float Merge(float A[], int p, int q, int r)
{
	float temp[100];
	int s = p;
	int t = q + 1;
	int k = 0;
	while (s - q <= 0.01&& t - r <= 0.01)
	{
		if (A[s] - A[t] <= 0)
		{
			temp[k] = A[s];
			s++;
		}
		else
		{
			temp[k] = A[t];
			t++;
		}
		k++;
	}
	if (abs(s - q - 1) < 0.01)
	{
		for (int op = k; op < r - p + 1; op++, t++)
		{
			temp[op] = A[t];
		}
	}
	else
	{
		for (int op = k; op < r - p + 1; op++, s++)
		{
			temp[op] = A[s];
		}
	}
	for (int i = 0; i < r - p + 1; i++)
	{
		A[p + i] = temp[i];
	}
	return 0.0f;
}

float Bottomupsort(float A[], int n)
{
	int t = 1;
	int s, i;
	float accept;
	while (t < n)
	{
		s = t;
		t = 2 * s;
		i = 0;
		while (i + t <= n)
		{
			accept = Merge(A, i, i + s - 1, i + t - 1);
			i += t;
		}
	}
	if (i + s < n)
		accept = Merge(A, i, i + s - 1, n - 1);
	return 0.0f;
}