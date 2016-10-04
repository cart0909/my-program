#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	//改串流
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	list<int> a, b;
	for (int i = 0; i < 10; ++i) {
		a.push_back(i);
	}
	auto it = a.begin();
	advance(it, 5);
	
	a.splice(a.begin(), a, it);
	// 把a的第六個放到a的第一個 

	b.push_back(50);
	b.push_back(100);
	it = a.begin();
	advance(it, 3);
	a.splice(it, b, b.begin());
	// 將b的第一個放到a的第四個
	system("pause");
	return 0;
}