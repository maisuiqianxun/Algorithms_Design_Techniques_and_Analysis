/*
Algorithm:Binary_search
input: a array include n increasing elements and target element x
output: if x exists in the array,then output the location;else output 0
author:Maisui_Y
time:2018.09.25
*/
#include<iostream>
using namespace std;
int main()
{
	int Len = 11;
	float array[11] = {1,3,5,6,8,12,14,15,16,20,56 };
	float target_x= 20;
	int j = 0;//for searching the target in array
	int low = 1;
	int mid;
	int high = Len;//initial the boundary of variable j
	while (low - high < 0.001&& abs(j - 0) < 0.001)
	{
		mid = ceil((low + high) / 2);
		if (abs(target_x - array[mid]) < 0.001)
			j = mid;
		else if (target_x - array[mid] < 0.001)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << "succeed locating in:" << j << endl;
	system("pause");
	return j;
}