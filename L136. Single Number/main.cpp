#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

int singleNumber(vector<int>& nums) {
	int x = 0;
	for (auto i : nums) {
		x ^= i;
	}
	return x;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> nums = { 1,0,1,2,3,0,5,2,7,7,5 };
	singleNumber(nums);
	system("pause");
	return 0;
}