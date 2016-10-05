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

int checkHeight(TreeNode* root) {
	if (!root) return 0;
	int left = checkHeight(root->left);
	int right = checkHeight(root->right);
	// TODO 加入違法條件
	if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
	// 
	return max(left, right)+1;
}

bool isBalanced(TreeNode* root) {
	return checkHeight(root) > 0;
}

int main() {
	//改串流
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
	isBalanced(a);
	system("pause");
	return 0;
}