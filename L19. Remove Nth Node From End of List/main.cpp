#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (n <= 0) return head;
	ListNode* prev = head, *end = head;
	for (int i = 0; i < n; ++i) {
		if(end) end = end->next;
	}
	if (end) {
		while (end->next) {
			prev = prev->next;
			end = end->next;
		}
		ListNode* remove = prev->next;
		// relink
		prev->next = remove->next;
		delete remove;
	}
	else {
		// 1->2->3  n = 3
		head = prev->next;
		delete prev;
	}
	return head;
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