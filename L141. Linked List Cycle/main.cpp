#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

//Definition for singly-linked list with a random pointer.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

// method 1: hash table
//bool hasCycle(ListNode *head) {
//	unordered_set<ListNode*> hash;
//	for (auto it = head; it != nullptr; it = it->next) {
//		if (hash.find(it) == hash.end()) {
//			hash.insert(it);
//		}
//		else {
//			return true;
//		}
//	}
//	return false;
//}

// method 2: two pointer
bool hasCycle(ListNode *head) {
	if (!head) return false;
	ListNode *slow = head, *fast = head->next;
	while (slow && fast) {
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
		if (slow == fast)
			return true;
	}
	return false;
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	system("pause");
	return 0;
}