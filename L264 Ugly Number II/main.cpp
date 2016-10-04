#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
	static vector<int> uglyArray = {1};
	static int L2index = 0, L3index = 0, L5index = 0;
	if (n <= 0) return 0;
	
	if (uglyArray.size() >= n) return uglyArray[n - 1];

	while (!(uglyArray.size() == n)) {
		initializer_list<int> compareNum = { uglyArray[L2index] * 2, uglyArray[L3index] * 3, uglyArray[L5index] * 5 };
		uglyArray.push_back(min(compareNum));
		if (uglyArray[L2index] * 2 == uglyArray.back()) ++L2index;
		if (uglyArray[L3index] * 3 == uglyArray.back()) ++L3index;
		if (uglyArray[L5index] * 5 == uglyArray.back()) ++L5index;
	}

	return uglyArray[n - 1];
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1000; i >= 0; --i) {
		cout << nthUglyNumber(i) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}