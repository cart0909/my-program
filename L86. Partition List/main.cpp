#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
	ListNode* leftRoot = NULL, *rightRoot = NULL;
	ListNode* leftCurNode = NULL, *rightCurNode = NULL;
	ListNode* curNode = head;
	while (curNode != NULL) {
		if (curNode->val < x) {
			if (leftRoot) {
				leftCurNode->next = curNode;
				leftCurNode = curNode;
			}
			else {
				leftRoot = curNode;
				leftCurNode = leftRoot;
			}
		}
		else {
			if (rightRoot) {
				rightCurNode->next = curNode;
				rightCurNode = curNode;
			}
			else {
				rightRoot = curNode;
				rightCurNode = rightRoot;
			}
		}
		curNode = curNode->next;
	}

	if (leftRoot) {
		head = leftRoot;
		leftCurNode->next = rightRoot;
		if(rightRoot)
			rightCurNode->next = NULL;
	}
	else if(rightRoot){
		head = rightRoot;
		rightCurNode->next = NULL;
	}
	else {
		head = NULL;
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
	a.push_back(new ListNode(2));
	a.push_back(new ListNode(4));
	a.push_back(new ListNode(3));
	a.push_back(new ListNode(5));
	a.push_back(new ListNode(7));
	a.push_back(new ListNode(10));
	a.push_back(new ListNode(1));
	a.push_back(new ListNode(2));
	a.push_back(new ListNode(4));
	for (int i = 0, n = a.size(); i < n-1; ++i) {
		a[i]->next = a[i + 1];
	}
	auto it = partition(a[0], 7);
	while (it != NULL) {
		cout << it->val << endl;
		it = it->next;
	}
	system("pause");
	return 0;
}