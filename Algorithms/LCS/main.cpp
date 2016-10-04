#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "LCS.h"
using namespace std;

int main() {
	{
		string x, y;
		x = "longestcommonsubsequence";
		y = "longestincreasingsubsequence";
		string output = lcs<string>(x, y);
		cout << output << endl;
	}
	{
		vector<int> x, y;
		x = { 2,5,7,9,3,1,2 };
		y = { 3,5,3,2,8 };
		vector<int> output = lcs<vector<int>>(x, y);
		for (auto& it : output) {
			cout << it << " ";
		}
		cout << endl;
	}
	{
		// this is example of Longest Increasing Subsequence
		vector<int> x, y;
		x = { 2, 16,5,7,9,3,1,2,12,7,3,15,17,21,3,1,32 };
		y = x;
		sort(y.begin(), y.end());
		vector<int> output = lcs<vector<int>>(x, y);
		for (auto& it : output) {
			cout << it << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}