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

void createTree(TreeNode* node, vector<int>::iterator lbegin, vector<int>::iterator lend, vector<int>::iterator rbegin, vector<int>::iterator rend) {
	auto lhalf = (lbegin + (lend - lbegin) / 2);
	auto rhalf = (rbegin + (rend - rbegin) / 2);
	node->left = new TreeNode(*lhalf);
	if(rhalf != rend)
		node->right = new TreeNode(*rhalf);
	if(lbegin != lhalf)
		createTree(node->left, lbegin, lhalf, lhalf + 1, lend);
	if(rbegin != rhalf)
		createTree(node->right, rbegin, rhalf, rhalf + 1, rend);
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.empty()) return nullptr;
	TreeNode* root = new TreeNode(nums[nums.size() / 2]);
	if(nums.size() > 1)
		createTree(root, nums.begin(), nums.begin() + nums.size() / 2, nums.begin() + nums.size() / 2 + 1, nums.end());
	return root;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	vector<int> nums;
	// 0 1 2
	for (int i = 0; i < 500; ++i) {
		nums.push_back(i);
	}
	sortedArrayToBST(nums);
	system("pause");
	return 0;
}