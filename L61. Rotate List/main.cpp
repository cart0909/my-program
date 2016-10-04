#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
	if (!head) return head;
	ListNode* curNode = head, *endNode = NULL;
	vector<ListNode*> cache;
	while (curNode) {
		cache.push_back(curNode);
		curNode = curNode->next;
	}
	k %= cache.size();
	if (k == 0) {
		return head;
	}
	else {
		cache.back()->next = cache.front();
		cache[cache.size() - k - 1]->next = NULL;
		return cache[cache.size() - k];
	}
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<ListNode*> a;
	a.push_back(new ListNode(1));
	a.push_back(new ListNode(2));
	a.push_back(new ListNode(3));
	a.push_back(new ListNode(3));
	a.push_back(new ListNode(4));
	a.push_back(new ListNode(4));
	a.push_back(new ListNode(5));
	for (int i = 0, n = a.size(); i < (n - 1); ++i) {
		a[i]->next = a[i + 1];
	}

	system("pause");
	return 0;
}