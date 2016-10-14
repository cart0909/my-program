#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numTrees(int n) {
	static vector<int> f = { 1, 1 };
	while (n >= f.size()) {
		f.push_back(0);
		for (int k = 1, i = f.size() - 1; k <= i; ++k) {
			f[i] += f[k - 1] * f[i - k];
		}
	}
	return f[n];
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	numTrees(3);
	system("pause");
	return 0;
}