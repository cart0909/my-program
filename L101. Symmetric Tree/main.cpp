#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkSymmetric(TreeNode* p, TreeNode* q) {
	if (!p && !q) 
		return true;
	else if (!p || !q) 
		return false;
	return (p->val == q->val) && checkSymmetric(p->left, q->right) && checkSymmetric(p->right, q->left);
}

bool isSymmetric(TreeNode* root) {
	return (root)? checkSymmetric(root->left, root->right) : true;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	system("pause");
	return 0;
}