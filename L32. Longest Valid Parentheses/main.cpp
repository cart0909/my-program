#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
	int max = 0, lpivot = -1, rpivot = s.size();
	std::stack<int> stack;
	for (int i = 0, n = s.size(); i < n; ++i) {
		if (s[i] == '(') {
			stack.push(i);
		}
		else {
			if (!stack.empty()) {
				stack.pop();
			}
			else {
				max = std::max(i - lpivot - 1, max);
				lpivot = i;
			}
		}
	}
	while (!stack.empty()) {
		auto index = stack.top();
		stack.pop();
		max = std::max(max, rpivot - index - 1);
		rpivot = index;
	}
	max = std::max(max, rpivot - lpivot - 1);
	return max;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s = "())((())(()()))((())(";
	cout << s.size() << endl;
	longestValidParentheses(s);
	system("pause");
	return 0;
}