#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	int closest = 0, minError = INT_MAX;
	if (nums.size() < 3) {
		return 0;
	}
	sort(nums.begin(), nums.end());
	for (auto i = nums.begin(), n = nums.end(); i < n - 2; ++i) {
		auto j = i + 1;
		if (i > nums.begin() && *i == *(i - 1)) continue;
		auto k = n - 1;
		while (j < k) {
			int sum = *i + *j + *k;
			if (sum < target) {
				int error = abs(target - sum);
				if (minError > error) {
					minError = error;
					closest = sum;
				}
				++j;
				while ((j < k) && (*j == *(j - 1))) ++j;
			}
			else if (sum > target) {
				int error = abs(target - sum);
				if (minError > error) {
					minError = error;
					closest = sum;
				}
				--k;
				while ((j < k) && (*k == *(k + 1))) --k;
			}
			else {
				return target;
			}
		}
	}
	return closest;
}

int main() {
	//§ï¦ê¬y
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-50, 50);

	vector<int> a;
	for (int i = 0; i < 50; ++i) {
		a.push_back(dis(gen));
	}
	
	cout << "[";
	for (int i = 0, n = a.size(); i < n-1; ++i) {
		cout << a[i] << ", ";
	}
	cout << a.back() << " ]" << endl;

	cout << dis(gen) << endl;
	//threeSumClosest(a, 1);
	//system("pause");
	return 0;
}