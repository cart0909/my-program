#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isValid(string s) {
	std::stack<char> stack;
	for (auto& it : s) {
		if (!stack.empty()) {
			switch (stack.top()) {
			case '(':
				if (it == ')') stack.pop();
				else stack.push(it);
				break;
			case '[':
				if (it == ']') stack.pop();
				else stack.push(it);
				break;
			case '{':
				if (it == '}') stack.pop();
				else stack.push(it);
				break;
			default:
				stack.push(it);
				break;
			}
		}
		else {
			stack.push(it);
		}
	}
	return stack.empty() ? true : false;
}


int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s = "(])";
	isValid(s);
	system("pause");
	return 0;
}