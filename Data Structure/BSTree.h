#pragma once
#include <functional>
#include "BinaryTree.h"

// 宣告
template<class T, class Compare = std::less<T>>
class BSTree;

// 類斯 std::set
template<class T, class Compare>
class BSTree : public BinaryTree<T> {
public:
	BSTree() {}
	~BSTree() {}

	bool insert(const T& data) {
		if (_root) {
			TreeNode<T>* curNode = _root,* prevNode = nullptr;
			while (curNode != nullptr && curNode->_data != data) {
				if (Compare()(data, curNode->_data)) { // left
					prevNode = curNode;
					curNode = curNode->_lChild;
				}
				else { // right
					prevNode = curNode;
					curNode = curNode->_rChild;
				}
			}
			if (curNode) {
				return false;
			}
			else {
				if (Compare()(data, prevNode->_data)) {
					curNode = new TreeNode<T>(data);
					linkNode(prevNode, curNode, LEFT_WAY);
				}
				else {
					curNode = new TreeNode<T>(data);
					linkNode(prevNode, curNode, RIGHT_WAY);
				}
				++_size;
				return true;
			}
		}
		else {
			_root = new TreeNode<T>(data);
			++_size;
		}
		return true;
	}

	int size() const {
		return _size;
	}

	bool empty() const {
		return _size == 0;
	}

	void clear() {
		// level_order traversal 適合拿來 delete all node 用
		std::queue<TreeNode<T>*> queue;
		if (_root) {
			queue.push(_root);
			while (!queue.empty()) {
				TreeNode<T>* temp = queue.front();
				queue.pop();
				if (temp->_lChild) {
					queue.push(temp->_lChild);
				}
				if (temp->_rChild) {
					queue.push(temp->_rChild);
				}
				delete temp;
			}
		}
		_root = nullptr;
		_size = 0;
	}

	iterator find(const T& data) {
		TreeNode<T>* curNode = search(data);
		return iterator(curNode, _root);
	}

	void erase(const iterator& pos){
		if (BinaryTree<T>::erase(pos))
			--_size;
	}
protected:
	int _size = 0;

	TreeNode<T>* search(const T& data) const {
		TreeNode<T>* curNode = _root;
		while (curNode != nullptr && curNode->_data != data) {
			if (Compare()(data, curNode->_data)) { // left
				curNode = curNode->_lChild;
			}
			else { // right
				curNode = curNode->_rChild;
			}
		}
		return curNode;
	}
};
