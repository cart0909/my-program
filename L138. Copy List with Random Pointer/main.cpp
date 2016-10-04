#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


//Definition for singly-linked list with a random pointer.
 struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


RandomListNode* copyRandomList(RandomListNode *head) {
	unordered_map<RandomListNode*, RandomListNode *> hash;
	for (auto it = head; it != NULL; it = it->next) {
		hash[it] = new RandomListNode(it->label);
	}
	for (auto it = head; it != NULL; it = it->next) {
		hash[it]->next = hash[it->next];
		hash[it]->random = hash[it->random];
	}
	return hash[head];
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	system("pause");
	return 0;
}