#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	//���y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	list<int> a, b;
	for (int i = 0; i < 10; ++i) {
		a.push_back(i);
	}
	auto it = a.begin();
	advance(it, 5);
	
	a.splice(a.begin(), a, it);
	// ��a���Ĥ��ө��a���Ĥ@�� 

	b.push_back(50);
	b.push_back(100);
	it = a.begin();
	advance(it, 3);
	a.splice(it, b, b.begin());
	// �Nb���Ĥ@�ө��a���ĥ|��
	system("pause");
	return 0;
}