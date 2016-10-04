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

vector<vector<int>> levelOrder(TreeNode* root) {
	std::queue<TreeNode*> s1, s2;
	std::queue<TreeNode*> *ptr1 = &s1, *ptr2 = &s2;
	vector<vector<int>> result;
	if (!root) return result;
	s1.push(root);
	while (!ptr1->empty()) {
		result.push_back(vector<int>());
		while (!ptr1->empty()) {
			TreeNode* now = ptr1->front();
			ptr1->pop();
			result.back().push_back(now->val);
			if (now->left) ptr2->push(now->left);
			if (now->right) ptr2->push(now->right);
		}
		swap(ptr1, ptr2);
	}
	return result;
}

int main() {
	//§ï¦ê¬y
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

	levelOrder(root);

	for (auto& it : tree) {
		delete it;
	}
	system("pause");
	return 0;
}