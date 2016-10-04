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
void preorderTraversalRecursive(TreeNode* curNode, vector<int>& visit) {
	visit.push_back(curNode->val);
	if (curNode->left) preorderTraversalRecursive(curNode->left, visit);
	if (curNode->right) preorderTraversalRecursive(curNode->right, visit);
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> temp;
	if(root)
		preorderTraversalRecursive(root, temp);
	return temp;
}
*/

// iterative
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> visit;
	if (root) {
		std::stack<TreeNode*> stack;
		TreeNode* now = root;
		while (now) {
			if (now->right) stack.push(now->right);
			visit.push_back(now->val);
			now = now->left;
			if (now == NULL && !stack.empty()) {
				now = stack.top();
				stack.pop();
			}
		}
	}
	return visit;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	system("pause");
	return 0;
}