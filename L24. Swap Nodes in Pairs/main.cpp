#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
	if (!head) return head;
	ListNode* rev1st = head->next, *rev2nd = head;
	if (!rev1st) return head;
	ListNode dummy(-1);
	ListNode *ptr = &dummy;

	while (rev1st) {
		ListNode* temp = rev1st->next;
		ptr->next = rev1st;
		ptr = ptr->next;
		ptr->next = rev2nd;
		ptr = ptr->next;
		if (temp) {
			rev2nd = temp;
			rev1st = rev2nd->next;
		}
		else {
			break;
		}
	}
	if (!rev1st) {
		ptr->next = rev2nd;
		ptr = ptr->next;
	}
	ptr->next = NULL;
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