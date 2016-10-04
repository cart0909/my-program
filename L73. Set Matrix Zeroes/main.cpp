#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <random>
using namespace std;

void setRowZero(vector<vector<int>>& matrix, int col) {
	for (int i = 0, n = matrix.size(); i < n; ++i) {
		matrix[i][col] = 0;
	}
}

void setColZero(vector<vector<int>>& matrix, int row) {
	for (int i = 0, n = matrix[row].size(); i < n; ++i) {
		matrix[row][i] = 0;
	}
}

void setZeroes(vector<vector<int>>& matrix) {
	vector<int> rows, cols;
	for (int i = 0, n = matrix.size(); i < n; ++i) {
		bool firstFlag = true;
		for (int j = 0, m = matrix[0].size(); j < m; ++j) {
			if (matrix[i][j] == 0) {
				if (firstFlag) {
					rows.push_back(i);
					firstFlag = false;
				}
				cols.push_back(j);
			}
		}
	}
	sort(cols.begin(), cols.end());
	auto last = unique(cols.begin(), cols.end());
	cols.erase(last, cols.end());
	for (auto& it : rows) {
		setColZero(matrix, it);
	}
	for (auto& it : cols) {
		setRowZero(matrix, it);
	}
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//std::random_device rd;
	//std::mt19937 gen(rd());
	//std::uniform_int_distribution<> dis(-50, 50);

	vector<vector<int>> a = { {0,1,2,3},{1,2,3,4},{1,2,3,4} };
	setZeroes(a);
	system("pause");
	return 0;
}