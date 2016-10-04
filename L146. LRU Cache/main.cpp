#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

// 學到list iterator是不動的
// 如果用vector
// hashtable很難跟vector::iterator一起用 因為vector改順續 iterator會亂跑
/*  範例
vector<int> test;
unordered_map<int, vector<int>::iterator> hash;
test.reserve(10);
for (int i = 0; i < 10; ++i) {
test.push_back(i);
hash.insert(pair<int, vector<int>::iterator>(i, test.begin()+i));
}
test.push_back(11);
*/

class LRUCache {
	typedef pair<int, int> CacheNode;
public:
	LRUCache(int capacity):_capacity(capacity) {
		
	}

	int get(int key) {
		auto it = _hashTable.find(key);
		if (it == _hashTable.end()) return -1;
		
		auto cacheNode = *it->second;
		_cacheList.erase(it->second);
		_cacheList.push_back(cacheNode);
		_hashTable[key] = --_cacheList.end();
		return cacheNode.second;
	}

	void set(int key, int value) {
		auto it = _hashTable.find(key);
		if (it == _hashTable.end()) {
			if (_cacheList.size() == _capacity) {
				_hashTable.erase(_cacheList.begin()->first);
				_cacheList.erase(_cacheList.begin());
			}
			_cacheList.push_back(CacheNode(key, value));
			_hashTable.insert(pair<int, list<CacheNode>::iterator>(key, --_cacheList.end()));
		}
		else {
			it->second->second = value;
			auto cacheNode = *it->second;
			_cacheList.erase(it->second);
			_cacheList.push_back(cacheNode);
			_hashTable[key] = --_cacheList.end();
		}
	}
private:
	list<CacheNode> _cacheList; // list<pair<key, value>>
	unordered_map<int, list<CacheNode>::iterator> _hashTable; // key, listIter
	int _capacity;
};

int main() {
	//改串流
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LRUCache cache(3);
	cache.set(1, 1);
	cache.set(2, 2);
	cache.set(3, 3);
	cache.set(4, 4);
	cout << cache.get(4) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(2) << endl;
	cout << cache.get(1) << endl;
	cache.set(5, 5);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cout << cache.get(5) << endl;
	system("pause");
	return 0;
}