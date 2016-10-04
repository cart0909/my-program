#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (m < 1 || m > n) return NULL;

	vector<ListNode*> cache;
	ListNode* curNode = head; // 1
	ListNode* prev = NULL, *next = NULL;
	int index = 1;
	while (index <= n && curNode != NULL) {
		if (index >= m) {
			cache.push_back(curNode);
		}
		else if (m != 1 && index == m - 1) {
			prev = curNode;
		}
		curNode = curNode->next;
		++index;
	}
	next = curNode;

	if (cache.size() != (n - m + 1)) {
		return NULL;
	}
	else {
		if (prev)
			prev->next = cache.back();
		else
			head = cache.back();
		for (int i = cache.size() - 1; i > 0; --i) {
			cache[i]->next = cache[i-1];
		}
		cache[0]->next = next;
	}
	return head;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	reverseBetween(a, 1, 4);
	system("pause");
	return 0;
}