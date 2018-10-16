/*
Algorithm:LCS( the longest common subsequence problem )
input: Two strings A and B of lengths n and m,respectively,over an alphabet "sum" sign.
output: The length of the longest common subsequence of A and B
author:Maisui_Y
time:2018.
environment: Windows 10 VS2015
*/
/*
NOTE: Observation: suppose that both i and j are greater than 0. then
if (A[i]=B[j])
L[i,j]=L[i-1,j-1]+1;
else
L[i,j]=max{L[i-1,j],L[i,j-1]};
###############at this algorithm, we adjust the code to make the space complexity is equal to O(length_B)##################
*/
#include <iostream> 
using namespace std;
int LCS(string A, string B, int length_A, int length_B);
int main()
{
	string A = "xyxxzxyzxy";
	string B = "zxzyyzxxyxxz";
	int length_A = A.size();
	int length_B = B.size();
	int longest_com_str;
	longest_com_str = LCS(A, B, length_A, length_B);
	cout << longest_com_str << endl;
	system("pause");
	return 0;
}

int LCS(string A, string B, int length_A, int length_B)
{
	int *L = new int[length_B+1]();
	int temp = 0;
	for (int i = 1; i <= length_A; i++)
	{
		int row = 0;
		for (int j = 1; j <= length_B; j++)
		{
			if (A[i-1] == B[j-1])
				temp = L[j - 1] + 1;
			else if (row > L[j])
				temp = row;
			else
				temp = L[j];
			L[j - 1] = row;
			row = temp;
		}
	}
	int Re = temp;
	delete[] L;
	return Re;
}

