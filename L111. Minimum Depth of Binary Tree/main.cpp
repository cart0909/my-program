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

int minDepth(TreeNode* root, int depth) {
	if (root->left == nullptr && root->right == nullptr)
		return depth;
	
	if (root->left == nullptr) {
		return minDepth(root->right, depth + 1);
	}
	else if (root->right == nullptr) {
		return minDepth(root->left, depth + 1);
	}
	else {
		return min(minDepth(root->left, depth + 1), minDepth(root->right, depth + 1));
	}
}

int minDepth(TreeNode* root) {
	if(root == nullptr) return 0;
	return minDepth(root, 1);
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	TreeNode* rt = new TreeNode(1);
	rt->left = new TreeNode(2);
	rt->right = new TreeNode(3);
	rt->left->right = new TreeNode(4);
	rt->right->left = new TreeNode(5);
	rt->left->right->left = new TreeNode(6);
	rt->left->right->right = new TreeNode(7);

	minDepth(rt, 1);
	system("pause");
	return 0;
}