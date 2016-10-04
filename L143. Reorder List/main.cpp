#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
	if (head) {
		vector<ListNode*> cache;
		for (auto it = head; it != NULL; it = it->next) {
			cache.push_back(it);
		}
		ListNode dummy(0);
		ListNode* nowPtr = &dummy;
		auto first = cache.begin(), last = cache.end() - 1;
		for (; last > first && first != last; ++first) {
			nowPtr->next = *first;
			nowPtr = nowPtr->next;
			nowPtr->next = *last;
			nowPtr = nowPtr->next;
			--last;
		}
		if (first == last) {
			nowPtr->next = *first;
			nowPtr = nowPtr->next;
		}
		nowPtr->next = NULL;
	}
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> a{ 1 };

	system("pause");
	return 0;
}