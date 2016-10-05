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

void flatten(TreeNode* root) {
	if (!root) return;
	flatten(root->right);
	flatten(root->left);
	TreeNode *left = root->left, *right = root->right;
	if (left) {
		root->right = left;
		while (left->right) {
			left = left->right;
		}
		left->right = right;
	}
	else {
		root->right = right;
	}
	root->left = nullptr;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	TreeNode* a = new TreeNode(50);
	a->left = new TreeNode(30);
	a->right = new TreeNode(70);
	auto temp = a->left;
	temp->left = new TreeNode(27);
	temp->left->left = new TreeNode(21);
	temp->right = new TreeNode(45);
	temp->right->right = new TreeNode(49);
	temp->right->left = new TreeNode(31);
	temp->right->left->right = new TreeNode(37);
	temp = a->right;
	temp->left = new TreeNode(57);
	temp->left->right = new TreeNode(60);
	temp->right = new TreeNode(77);
	flatten(a);
	system("pause");
	return 0;
}