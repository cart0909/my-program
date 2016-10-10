#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 這太神， 這不是我自己想的
void connect(TreeLinkNode *root) {
	while (root) {
		TreeLinkNode *next = nullptr, *prev = nullptr;
		for (; root; root = root->next) {
			if (!next) next = root->left ? root->left : root->right;

			if (root->left) {
				if (prev) prev->next = root->left;
				prev = root->left;
			}
			if (root->right) {
				if (prev) prev->next = root->right;
				prev = root->right;
			}
		}
		root = next;
	}
}

int main() {
	//改串流
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	system("pause");
	return 0;
}