#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (!head) return head;
	ListNode dummyBegin(head->val-1); // 故意跟頭不一樣
	ListNode* curNode = &dummyBegin;
	
	while (head) {
		if (head->val != curNode->val) {
			curNode->next = head;
			curNode = curNode->next;
			head = head->next;
		}
		else {
			ListNode* prev = head;
			head = head->next;
			delete prev;
		}
	}
	curNode->next = NULL;
	return dummyBegin.next;
}

int main() {
	//改串流
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(1);
	a->next = b;
	deleteDuplicates(a);
	system("pause");
	return 0;
}