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
void postorderTraversalRecursive(TreeNode* curNode, vector<int>& visit) {
	if (curNode->left) postorderTraversalRecursive(curNode->left, visit);
	if (curNode->right) postorderTraversalRecursive(curNode->right, visit);
	visit.push_back(curNode->val);
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> temp;
	if (root) {
		postorderTraversalRecursive(root, temp);
	}
	return temp;
}
*/

// iterative
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	stack<TreeNode*> s;
	TreeNode *p = root, *q = nullptr;
	do {
		while (p != nullptr) {
			s.push(p);
			p = p->left;
		} // 一直往左跑
		q = nullptr;
		while (!s.empty()) {
			p = s.top();
			s.pop();
			if (p->right == q) { // 右邊不存在或著是經過
				result.push_back(p->val);
				q = p;
			}
			else {
				s.push(p);
				p = p->right;
				break;
			}
		}
	} while (!s.empty());

	return result;
}

int main() {
	//改串流
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<TreeNode*> tree;
	for (int i = 0; i < 15; ++i) {
		tree.push_back(new TreeNode(i+1));
	}

	TreeNode* root = tree[14];
	root->left = tree[6];
	root->right = tree[13];
	tree[6]->left = tree[2];
	tree[6]->right = tree[5];
	tree[13]->left = tree[9];
	tree[13]->right = tree[12];
	tree[2]->left = tree[0];
	tree[2]->right = tree[1];
	tree[5]->left = tree[3];
	tree[5]->right = tree[4];
	tree[9]->left = tree[7];
	tree[9]->right = tree[8];
	tree[12]->left = tree[10];
	tree[12]->right = tree[11];

	postorderTraversal(root);

	for (auto& it : tree) {
		delete it;
	}
	system("pause");
	return 0;
}