#include <iostream>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> solutions;
	if (nums.size() < 3) {
		return solutions;
	}
	sort(nums.begin(), nums.end());
	for (auto i = nums.begin(), last = nums.end(); i < last - 2; ++i) {
		auto j = i + 1;
		if (i > nums.begin() && *i == *(i - 1)) continue;
		auto k = last - 1;
		while (j < k) {
			if (*i + *j + *k < 0) {
				++j;
				while (*j == *(j - 1) && j < k) ++j;
			}
			else if (*i + *j + *k > 0) {
				--k;
				while (*k == *(k + 1) && j < k) --k;
			}
			else {
				solutions.push_back({ *i, *j, *k });
				++j;
				--k;
				while ((*j == *(j - 1)) && (j < k)) ++j;
				while ((*k == *(k + 1)) && (j < k)) --k;
			}
		}
	}

	return solutions;
}

int main() {
	//§ï¦ê¬y
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-50, 50);

	vector<int> a = { -1,0,1,2,-1,-4 };
	//for (int i = 0; i < 70; ++i) {
	//	a.push_back(dis(gen));
	//}
	//sort(a.begin(), a.end());
	cout << "[";
	for (int i = 0, n = a.size(); i < n - 1; ++i) {
		cout << a[i] << " ,";
	}
	cout << a.back() << "]" << endl;
	vector<vector<int>> y;
	y = threeSum(a);
	//system("pause");
	return 0;
}