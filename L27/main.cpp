#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == val) {
			nums[i] = nums.back();
			--i;
			nums.pop_back();
		}
	}
	return nums.size();
}

int main() {
	//§ï¦ê¬y
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-100, 100);

	vector<int> a;
	for (int i = 0; i < 300; ++i) {
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