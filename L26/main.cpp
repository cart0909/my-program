#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	int i = 0;
	while (i != (nums.size()-1)) {
		if (nums[i] == nums[i + 1])
			nums.erase(nums.begin() + i);
		else
			++i;
	}
	return nums.size();
}
	
int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 1000);

	vector<int> x;
	for (int i = 0; i < 300; ++i) {
		x.push_back(dis(gen));
	}
	sort(x.begin(), x.end());
	for (auto& it : x) {
		cout << it << " ";
	}
	cout << endl;

	cout << removeDuplicates(x) << endl;
	for (auto& it : x) {
		cout << it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}