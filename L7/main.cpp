#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

int reverse(int x) {
	ostringstream os;
	os << x;
	string xs = os.str();
	os.str("");
	os.clear();
	
	bool minus = false;
	if (xs[0] == '-') {
		minus = true;
		xs.erase(xs.begin());
	}
	string reverseString;
	for (int i = xs.size() - 1; i >= 0; --i) {
		reverseString.push_back(xs[i]);
	}
	long long y = stoll(reverseString);
	if (minus)
		y *= -1;

	if (y > INT_MAX || y < INT_MIN)
		y = 0;
	return (int)y;
}

int main() {
	//§ï¦ê¬y
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int x;
	cin >> x;
	cout << sizeof(long long) << endl;
	cout << reverse(x) << endl;
	return 0;
}