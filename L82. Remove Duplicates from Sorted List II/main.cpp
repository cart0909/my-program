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
	ListNode dummy(head->val - 1); // 故意跟head值不同
	ListNode* newListCurNode = &dummy;
	while (head) {
		auto next = head->next;
		if (next && head->val != next->val) {
			newListCurNode->next = head;
			newListCurNode = head;
			head = next;
			newListCurNode->next = NULL;
		}
		else if(next && head->val == next->val){
			while (next && next->val == head->val) {
				delete head;
				head = next;
				next = next->next;
			}
			delete head;
			head = next;
		}
		else {
			newListCurNode->next = head;
			newListCurNode = head;
			newListCurNode->next = NULL;
			head = NULL;
		}
	}
	return dummy.next;
}

int main() {
	//改串流
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
	deleteDuplicates(a[0]);
	system("pause");
	return 0;
}