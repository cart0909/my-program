#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	vector<int> diff;
	int  n = gas.size();
	diff.reserve(gas.size());
	for (int i = 0; i < n; ++i) {
		diff.push_back(gas[i] - cost[i]);
	}
	int sum = 0, startIndex = 0, nowIndex = 0;
	sum = diff[startIndex];
	nowIndex = (nowIndex+1) % n;
	if (nowIndex == 0) { // nowIndex == 0
		return (sum >= 0) ? 0 : -1;
	}
	while (startIndex != n && !(startIndex == nowIndex)) {
		while (sum < 0) {
			sum -= diff[startIndex];
			++startIndex;
		}
		sum += diff[nowIndex];
		nowIndex = (nowIndex + 1) % n;
	}
	if (startIndex == n || sum < 0) {
		return -1;
	}
	return startIndex;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> gas = { 4,5,6,1,1 }, cost = {5,4,4,3,2};
	cout << canCompleteCircuit(gas, cost) << endl;
	system("pause");
	return 0;
}