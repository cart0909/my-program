#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

//Search in Rotated Sorted Array
int search(vector<int>& nums, int target) {
	int first = 0, end = nums.size();

	while (first != end) {
		int mid = first + (end - first) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] >= nums[first] && nums[mid] >= nums[end - 1]) { // 小大小
			if (target >= nums[first] && target < nums[mid]) {
				end = mid;
			}
			else {
				first = mid + 1;
			}
		}
		else if (nums[mid] <= nums[first] && nums[mid] <= nums[end - 1]) { //大小大
			if (target > nums[mid] && target <= nums[end - 1]) {
				first = mid + 1;
			}
			else {
				end = mid;
			}
		}
		else { // normal
			if (target > nums[mid]) { // right
				first = mid + 1;
			}
			else { // left
				end = mid;
			}
		}
	}
	return -1;
}

// normal binary Search
// the input x must sorted
int binarySearch(const vector<int>& x, int target) {
	int first = 0, end = x.size();
	while (first != end) {
		int mid = first + (end - first) / 2;
		if (x[mid] == target) {
			return mid;
		}
		else if (target > x[mid]) { // right
			first = mid + 1;
		}
		else { // left
			end = mid;
		}
	}
	return -1;
}

int main() {
	//改串流
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 200);
	vector<int> x;
	for (int i = 0; i < 100; ++i) {
		x.push_back(dis(gen));
	}
	sort(x.begin(), x.end());

	int target = dis(gen);
	target = 1;

	dis = uniform_int_distribution<>(0, x.size()-1);
	int pivot = dis(gen);
	vector<int> newx = { 3 ,1};
	//newx.insert(newx.begin(), x.end() - pivot, x.end());
	//newx.insert(newx.end(), x.begin(), x.end() - pivot);
	

	cout << "array: " << endl;
	for (auto& it : newx) {
		cout << it << " ";
	}
	cout << endl;

	cout << "search:" << target << endl;
	cout << "index: " << search(newx, target) << endl;

	system("pause");
	return 0;
}