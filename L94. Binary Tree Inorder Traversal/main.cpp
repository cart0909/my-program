#include <iostream>
#include <stack>
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

// recursive
/*
void inorderTraversalRecursive(TreeNode* curNode, vector<int>& visit) {
	if (curNode->left) inorderTraversalRecursive(curNode->left, visit);
	visit.push_back(curNode->val);
	if (curNode->right) inorderTraversalRecursive(curNode->right, visit);
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> temp;
	if (root) {
		inorderTraversalRecursive(root, temp);
	}
	return temp;
}
*/

// iterative
vector<int> inorderTraversal(TreeNode* root) {
	TreeNode* now = root;
	vector<int> visit;
	std::stack<TreeNode*> stack;
	while (!stack.empty() || now != nullptr) {
		if (now != nullptr) {
			stack.push(now);
			now = now->left;
		}
		else {
			now = stack.top();
			stack.pop();
			visit.push_back(now->val);
			now = now->right;
		}
	}
	return visit;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//TreeNode* a = new TreeNode(50);
	//a->left = new TreeNode(30);
	//a->right = new TreeNode(70);
	//auto temp = a->left;
	//temp->left = new TreeNode(27);
	//temp->left->left = new TreeNode(21);
	//temp->right = new TreeNode(45);
	//temp->right->right = new TreeNode(49);
	//temp->right->left = new TreeNode(31);
	//temp->right->left->right = new TreeNode(37);
	//temp = a->right;
	//temp->left = new TreeNode(57);
	//temp->left->right = new TreeNode(60);
	//temp->right = new TreeNode(77);
	TreeNode* a = new TreeNode(3);
	a->left = new TreeNode(2);
	a->right = new TreeNode(4);
	a->right->left = new TreeNode(1);
	inorderTraversal(a);

	system("pause");
	return 0;
}