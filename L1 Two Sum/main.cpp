#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> twoSumIndex;
	if (nums.size() < 2) 
		return twoSumIndex;

	unordered_map<int, int> hash;
	for (int i = 0, n = nums.size(); i < n; ++i)
		hash.insert(pair<int, int>(nums[i], i));

	for (int i = 0, n = nums.size(); i < n; ++i) {
		auto solIter = hash.find(target - nums[i]);
		if (solIter != hash.end()) {
			if (i == solIter->second)
				continue;
			twoSumIndex.push_back(i);
			twoSumIndex.push_back(solIter->second);
			return twoSumIndex;
		}
	}
	return twoSumIndex;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector<int> a = { 3,2,4 };
	twoSum(a, 6);
	system("pause");
	return 0;
}