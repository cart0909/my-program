#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

int myAtoi(string str) {
	// cut space
	string newStr;
	string::iterator it = str.begin();
	while (*it == ' ' || *it == '\t') {
		it++;
	}
	newStr.insert(newStr.begin(), it, str.end());
	int output = 0;
	try {
		output = stoi(newStr);
	}
	catch (const std::out_of_range& oor) {
		if (newStr[0] == '-')
			return INT_MIN;
		else
			return INT_MAX;
	}
	catch (const std::invalid_argument& ia) {
		
	}
	return output;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cout << myAtoi("9223372036854775809") << endl;

	system("pause");
	return 0;
}