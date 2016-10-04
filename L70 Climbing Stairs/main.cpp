#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int climbStairs(int n) {
	static vector<int> way{ 1, 2 };
	if (n <= 0) 
		return way[0];
	
	while (!(way.size() >= n)) {
		way.push_back(*(way.end()-1) + *(way.end()-2));
	}

	return way[n - 1];
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	climbStairs(70);
	climbStairs(7);
	system("pause");
	return 0;
}