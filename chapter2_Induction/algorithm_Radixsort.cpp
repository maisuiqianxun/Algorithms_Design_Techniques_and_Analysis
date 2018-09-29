/*
Algorithm:Radixsort
input: A linked list of numbers L={a1,a2,...,an} and k, the number of digits.
output: L sorted in nondecreasing order.
/*
author:Maisui_Y
time:2018.09.28
environment: Windows 10 VS2015
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int Ridixsort(vector<int> &L, int k);
int *data_to_array(int a, int k);
int main()
{
	vector<int> L = { 7467,1247,3275,6792,9187,9134,4675,1239 };
	vector<int>::iterator it;
	for (int i = 0; i < 8; i++)
	{
		cout << L.at(i) << "  ";
	}
	cout << endl;
	int M;
	M = Ridixsort(L, 4);
	for (int i = 0; i < 8; i++)
	{
		cout << L.at(i) << "  ";
	}
	cout << endl;
	system("pause");
	return 0;
}
int Ridixsort(vector<int>& L, int k)
{
	int length = L.size();
	for (int j = 0; j < length; j++)
	{
		vector<int> L_k[10];
		vector<int>::iterator it2;
		int a;
		int *array_real;
		while (!L.empty())
		{
			it2 = L.end() - 1;
			a = L.back();
			L.erase(it2);
			array_real = data_to_array(a, k);
			L_k[array_real[j]].push_back(a);
		}
		L = L_k[0];
		for (int i = 1; i < 10; i++)
		{
			L.insert(L.end(), L_k[i].begin(), L_k[i].end());
		}
	}
	return 0;
}
int *data_to_array(int a, int k)
{
	static int assist_array[100] = { 0 };
	int m, n;
	for (int i = k - 1; i >= 0; i--)
	{
		m = a / pow(10, i);
		n =(a / pow(10, i + 1));
		assist_array[i] = m - n * 10;  //if I set use the"a / pow(10, i)" and the "a / pow(10, i + 1)" to calculate 
		                               //" assist_array[i]",the code will not output the right outcome,why?
	}
	return assist_array;
}