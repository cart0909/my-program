#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

bool myNextPermutation(vector<int>::iterator first, vector<int>::iterator last) {
	if (first == last) return false;
	auto i = last;
	if (first == --i) return false;

	while (1) {
		auto i1 = i;
		if (*--i < *i1) {
			auto i2 = last;
			while (!(*i < *--i2));
			iter_swap(i, i2);
			reverse(i1, last);
			return true;
		}
		if (i == first) {
			reverse(first, last);
			return false;
		}
	}
}

void nextPermutation(vector<int>& nums) {
	myNextPermutation(nums.begin(), nums.end());
}

int main() {
	//§ï¦ê¬y
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-100, 100);

	//threeSumClosest(a, 1);
	//system("pause");
	return 0;
}