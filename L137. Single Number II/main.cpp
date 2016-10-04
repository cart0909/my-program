#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <bitset>
using namespace std;

int singleNumber(vector<int>& nums) {
	vector<int> bitCount;
	bitCount.insert(bitCount.begin(), 8*sizeof(int), 0);
	for (auto& it : nums) {
		bitset<8 * sizeof(int)> num(it);
		for (int j = 0, n = bitCount.size(); j < n; ++j) {
			bitCount[j] += num[j];
		}
	}
	int single = 0;
	for (int j = 0, n = bitCount.size(); j < n; ++j) {
		bitCount[j] %= 3;
		single += bitCount[j] << j;
	}

	return single;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> nums = { -2,-2,-2,-10,3,3,3 };
	singleNumber(nums);
	system("pause");
	return 0;
}