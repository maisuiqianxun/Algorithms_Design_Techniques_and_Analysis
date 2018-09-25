/*
Algorithm:Linear_search
input: a array include n elements and target element x
output: if x exists in the array,then output the location;else output 0
author:Maisui_Y
time:2018.09.25
*/
#include<iostream>
using namespace std;
int main()
{
	int Len = 5;
	float array[5] = { 12,8,9,10,23 };
	float target = 23;
	int j = 0;//for searching the target in array
	while (j<Len && abs(array[j] - target)>0.001)
	{
		j++;
	}
	if (array[j] - target < 0.001)
	{
		cout << "succeed locating in:" << j << endl;
		system("pause");
		return j;
	}

	else
		return 0;
	cout << j;


}