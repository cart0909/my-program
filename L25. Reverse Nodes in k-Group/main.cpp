#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
	if (!head) return head;
	ListNode dummy(0), *nowPtr = &dummy;
	ListNode* groupBegin = head, *groupEnd = head;
	bool isGroup = true;
	do {
		groupBegin = groupEnd;
		for (int i = 0; i < k; ++i) {
			if (groupEnd)
				groupEnd = groupEnd->next;
			else {
				isGroup = false;
				break;
			}
		}
		if (isGroup) {
			stack<ListNode*> Stack;
			for (auto it = groupBegin; it != groupEnd; it = it->next) {
				Stack.push(it);
			}
			while (!Stack.empty()) {
				nowPtr->next = Stack.top();
				Stack.pop();
				nowPtr = nowPtr->next;
				nowPtr->next = NULL;
			}
		}
		else {
			nowPtr->next = groupBegin;
		}
	} while (groupEnd);

	return dummy.next;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<ListNode*> a;
	a.push_back(new ListNode(1));
	a.push_back(new ListNode(2));
	a.push_back(new ListNode(3));
	a.push_back(new ListNode(4));
	a.push_back(new ListNode(5));
	a.push_back(new ListNode(6));
	a.push_back(new ListNode(7));
	for (int i = 0, n = a.size(); i < (n - 1); ++i) {
		a[i]->next = a[i + 1];
	}
	reverseKGroup(a[0], 3);
	system("pause");
	return 0;
}