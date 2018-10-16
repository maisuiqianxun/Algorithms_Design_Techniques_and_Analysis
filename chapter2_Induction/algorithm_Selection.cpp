/*
Algorithm:Selection:finding the Median and the kth smallest element
input: An array A[1,...n] of n elements and an integer k,1<=k<=n
output: The kth smallest element in A
author:Maisui_Y
time:2018.09.30
environment: Windows 10 VS2015
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
float select(float A[], int low,int high,int k);
int main()
{
	float A[25] = { 8,33,17,51,57,49,35,11,25,37,14,3,2,13,52,12,6,29,32,54,5,16,22,23,7 };
	int k = 13;     
	float goal;
	goal = select(A, 0, 24, k);
	cout << goal << endl;
	system("pause");
	return 0;
}
float select(float A[], int low, int high, int k)
{
	int p,q;
	float mm;
	p = high - low + 1;
	if (p < 10)
	{
		sort(A+low, A+high+1); //notice the low boundary and the high boundary of "sort", in the other words,notice the high+1;
		return A[k-1];
	}
	else
	{
		q = ceil(p / 5);
		float assist[100] = { 0 };  //max(q)<100
		float A_lower[500] = { 0 };
		float A_equal[500] = { 0 };
		float A_higher[500] = { 0 };
		int x = 0;
		int y = 0;
		int z = 0; //record the length of three subarray
		for (int i = 0; i < q; i++)
		{
			sort(A+low + i * 5, A+low + 5 + i * 5);   
			assist[i] = A[low + 2 + i * 5];
		}
		mm = select(assist, 0, q-1, floor(q / 2));
		for (int j = low; j <= high; j++)
		{
			if (A[j] < mm)
				A_lower[x++] = A[j];
			else if (A[j]>mm)
				A_higher[z++] = A[j];
			else
				A_equal[y++] = A[j];
		}
		if (x >= k)
			return select(A_lower, 0, x - 1, k);
		else if (x + y >= k)
			return mm;
		else if (x + y < k)
			return select(A_higher, 0, z - 1, k - x - y);
	}
}
