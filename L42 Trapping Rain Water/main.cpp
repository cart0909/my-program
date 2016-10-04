#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
	vector<int> maxFL2R, maxFR2L;
	int maxL = 0, maxR = 0, totoal = 0;
	for (int i = 0, n = height.size(); i < n; ++i) {
		if (height[i] > maxL) maxL = height[i];
		if (height[n - 1 - i] > maxR) maxR = height[n - 1 - i];
		maxFL2R.push_back(maxL);
		maxFR2L.push_back(maxR);
	}
	reverse(maxFR2L.begin(), maxFR2L.end());
	for (int i = 0, n = height.size(); i < n; ++i) {
		totoal += min(maxFL2R[i]-height[i], maxFR2L[i]-height[i]);
	}
	return totoal;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> a = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	trap(a);
	system("pause");
	return 0;
}