#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	auto i = s.begin(), j = prev(s.end());
	while (j > i) {
		if (!isalnum(*i)) {
			++i;
			continue;
		}
		else if (!isalnum(*j)) {
			--j;
			continue;
		}
		else if (*i != *j) {
			return false;
		}
		++i;
		--j;
	}
	return true;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s = "A man, a plan, a canal: Panama";
	isPalindrome(s);
	system("pause");
	return 0;
}