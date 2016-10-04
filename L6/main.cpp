#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
	assert(numRows > 0);
	if (numRows == 1) {
		return s;
	}
	else {
		vector<string> bucket;
		bucket.insert(bucket.begin(), numRows, "");
		int bucketIndex = 0, stringIndex = 0, stringSize = s.size();
		bool inv = false;
		while (stringIndex != stringSize) {
			if(!inv)
				bucket[bucketIndex++].push_back(s[stringIndex]);
			else
				bucket[bucketIndex--].push_back(s[stringIndex]);
			if (bucketIndex == 0 || bucketIndex == numRows - 1)
				inv = !inv;
			stringIndex++;
		}
		string output;
		for (auto& it : bucket)
			output += it;
		return output;
	}
}

int main() {
	//§ï¦ê¬y
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s;
	int i;
	cin >> s >> i;
	cout << convert(s, i) << endl;
	
	return 0;
}