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

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// bottom-up
TreeNode* sortedListToBST(ListNode*& list, int start, int end) {
	if (start > end)
		return nullptr;
	int mid = start + (end - start) / 2;
	TreeNode* leftChild = sortedListToBST(list, start, mid - 1);
	TreeNode* parent = new TreeNode(list->val);
	parent->left = leftChild;
	list = list->next;
	parent->right = sortedListToBST(list, mid + 1, end);
	return parent;
}

TreeNode* sortedListToBST(ListNode* head) {
	int len = 0;
	ListNode* p = head;
	while (p) {
		p = p->next;
		++len;
	}
	return sortedListToBST(head, 0, len - 1);
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	system("pause");
	return 0;
}