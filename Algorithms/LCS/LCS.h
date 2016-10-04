#pragma once
#include <algorithm>
#include <stack>
// Longest Common Subsequence Algorithm
// the input format is like string and vector<T>

// Computation the length of Longest Common Subsequence
// Complexity O(2^n)
template<class T>
int lcs_len(const T& x, const T& y) {
	if (x.size() == 0 || y.size() == 0)
		return 0;

	T xx, yy;
	xx.insert(xx.begin(), x.begin(), x.end() - 1);
	yy.insert(yy.begin(), y.begin(), y.end() - 1);

	if (*(x.end() - 1) == *(y.end() - 1))
		return lcs_len(xx, yy) + 1;
	else
		return max(lcs_len(xx, y), lcs_len(x, yy));
}

// Computation one solution of Longest Common Subsequence 
// using dynamcis programing
// Complexity O(n^2) maybe...
template<class T>
T lcs(const T& x, const T& y) {
	int n = x.size(), m = y.size();

	vector<vector<int>> table; // a hashtable, but we'll use it as a 2D array here
	table.reserve(n + 1);
	table.insert(table.begin(), n + 1, vector<int>());
	for (auto& it : table) {
		it.reserve(m + 1);
		it.insert(it.begin(), m + 1, 0);
	}

	for (int i = 0; i < (n + 1); ++i) {			// i = 0, 1, ..., n
		for (int j = 0; j < (m + 1); ++j) {		// j = 0, 1, ..., m
			if (i == 0 || j == 0) {
				table[i][j] = 0;
			}
			else if (x[i - 1] == y[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}

	// now, table[n][m] is the length of LCS of x and y

	// let's go one step further and reconstruct
	// the actual sequence from DP table
	stack<int> LCSIndex;
	{
		int i = n, j = m;
		while (i != 0 || j != 0) {
			if (table[i][j] == 0) {
				break;
			}
			else if (table[i][j] == table[i - 1][j]) {
				i--;
			}
			else if (table[i][j] == table[i][j - 1]) {
				j--;
			}
			else {
				i--;
				j--;
				LCSIndex.push(i);
			}
		}
	}
	T LCS;
	while (!LCSIndex.empty()) {
		LCS.push_back(x[LCSIndex.top()]);
		LCSIndex.pop();
	}
	return LCS;
}