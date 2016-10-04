#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	unordered_map<int, bool> hash;
	int maxConsecutiveNum = 0;
	for (auto& it : nums) {
		hash.insert(pair<int, bool>(it, false));
	}
	for (auto& it : hash) {
		if (!it.second) {
			int startKey = it.first, consecutiveNum = 1, nowKeyPtr = startKey;
			it.second = true;
			auto hashIter = hash.find(--nowKeyPtr);
			while (hashIter != hash.end()) {
				hashIter->second = true;
				++consecutiveNum;
				hashIter = hash.find(--nowKeyPtr);
			}
			nowKeyPtr = startKey;
			hashIter = hash.find(++nowKeyPtr);
			while (hashIter != hash.end()) {
				hashIter->second = true;
				++consecutiveNum;
				hashIter = hash.find(++nowKeyPtr);
			}

			if (consecutiveNum > maxConsecutiveNum) {
				maxConsecutiveNum = consecutiveNum;
			}
		}
	}
	return maxConsecutiveNum;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-1000, 1000);

	unordered_set<int> a;
	for (int i = 0; i < 1500; ++i) {
		a.insert(dis(gen));
	}

	cout << "[";
	for (auto& it : a) {
		cout << it << ", ";
	}
	cout << "]";

	//system("pause");
	return 0;
}