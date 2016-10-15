#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root, long long high, long long low) {
	if (!root) return true;
	if (root->left) 
		if (root->val <= root->left->val)
			return false;
	if (root->right) 
		if (root->val >= root->right->val)
			return false;
	if (root->val >= high) return false;
	if (root->val <= low) return false;

	return isValidBST(root->left, root->val, low) && isValidBST(root->right, high, root->val);
}

bool isValidBST(TreeNode* root) {
	return isValidBST(root, (long long)INT_MAX+1, (long long)INT_MIN-1);
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	TreeNode root(INT_MAX);
	isValidBST(&root);
	system("pause");
	return 0;
}