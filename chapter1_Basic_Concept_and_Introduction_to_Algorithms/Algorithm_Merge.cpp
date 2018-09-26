/*
Algorithm:Merge
input: An array A[1...m] of elements and three indices p,q,r,with 1<=p<=q<=r<=m,such that both
the subarray A[p...q] and A[q+1..r] are sorted individually in nondcreasing order.
output: A[p..r] contains the result of merging the two subarrays A[p..q] and A[q+1..r].
author:Maisui_Y
time:2018.09.25
*/
#include<iostream>
using namespace std;
float Merge(float A[], int p, int q, int r);
int main()
{
	int Len = 18;
	float array[18] = { 3,8,4,6,5,1,3,5,2,4,6,8,10,23,43,12,3,45 };
	int p = 5;
	int q = 7;
	int r = 12;  //three indices
	float mn;
	mn = Merge(array, p, q, r);
	for (int ui = p; ui < r + 1; ui++)
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