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
	bool same = false;
	while (i != (nums.size()-1)) {
		if (nums[i] == nums[i + 1]) {
			if (same) {
				nums.erase(nums.begin() + i);
			}
			else {
				same = true;
				++i;
			}
		}
		else {
			same = false;
			++i;
		}
	}
	return nums.size();
}
	
int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 20);

	vector<int> x = {1,1,1};
	//for (int i = 0; i < 20; ++i) {
	//	x.push_back(dis(gen));
	//}
	//sort(x.begin(), x.end());
	//for (auto& it : x) {
	//	cout << it << " ";
	//}
	//cout << endl;

	cout << removeDuplicates(x) << endl;
	for (auto& it : x) {
		cout << it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}