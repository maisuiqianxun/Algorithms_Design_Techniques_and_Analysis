/*
Algorithm:Permutations
input: A positive integer n
output: All permutations of the numbers 1,2,...,n
author:Maisui_Y
time:2018.09.28
environment: Windows 10 VS2015
*/
#include<iostream>
using namespace std;
int perm1(int m,int n,int P[]);
int main()
{
	static int n = 2;
	int P[20]; //define a large array for save.
	for (int i = 0; i < n; i++)
		P[i] = i;
	perm1(0,n,P);
	system("pause");
	return 0;
}
int perm1(int m,int n,int P[])
{
	int temp;
	if (abs(m - n) < 0.01)
	{
		for (int j = 0; j < n; j++)
		{
			cout << P[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int k = m; k < n; k++)
		{
			temp = P[m];
			P[m] = P[k];
			P[k] = temp;
			temp = perm1(m + 1, n, P);
			temp = P[m];
			P[m] = P[k];
			P[k] = temp;
			
		}
	}
	return 0;
}
