#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<int> grayCode(int n) {
	static vector<vector<int>> dict{ {0,1} };
	if (n <= 0) return vector<int>({0});

	while (!(dict.size() >= n)) {
		dict.push_back(vector<int>());
		dict.back().insert(dict.back().begin(), (dict.end() - 2)->begin(), (dict.end() - 2)->end());
		dict.back().insert(dict.back().begin(), (dict.end() - 2)->begin(), (dict.end() - 2)->end());
		reverse(dict.back().begin()+ dict.back().size()/2, dict.back().end());
		int bit = 1 << (dict.size()-1);
		for (int i = dict.back().size() / 2, n = dict.back().size(); i < n; ++i)
			dict.back()[i] |= bit;
	}

	return dict[n-1];
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector<int> a;
	a = move(grayCode(3));
	for (auto& it : a) {
		cout << it << endl;
	}
	system("pause");
	return 0;
}