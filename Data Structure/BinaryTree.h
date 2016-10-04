#pragma once
#include <vector>
#include <stack>
#include <queue>
// 宣告
template<class T>
class TreeNode;

template<class T>
class BinaryTree;

// 定義
template<class T>
class TreeNode {
public:
	TreeNode(){}
	TreeNode(const T& data):_data(data){}
	~TreeNode(){}
	// traversal
	void post_order(std::vector<T>& visitData) const {
		if (_lChild) {
			_lChild->post_order(visitData);
		}
		if (_rChild) {
			_rChild->post_order(visitData);
		}
		visitData.push_back(_data);
	}

	void pre_order(std::vector<T>& visitData) const {
		visitData.push_back(_data);
		if (_lChild) {
			_lChild->pre_order(visitData);
		}
		if (_rChild) {
			_rChild->pre_order(visitData);
		}
	}

	void in_order(std::vector<T>& visitData) const {
		if (_lChild) {
			_lChild->in_order(visitData);
		}
		visitData.push_back(_data);
		if (_rChild) {
			_rChild->in_order(visitData);
		}
	}

	TreeNode* _lChild = nullptr, *_rChild = nullptr;
	TreeNode* _parent = nullptr;
	T _data;
};


template<class T>
class BinaryTree {
public:
	BinaryTree(){
		// for debug
		//_root = new TreeNode<string>();
		//_root->_data = "A";

		//_root->_lChild = new TreeNode<string>();
		//_root->_lChild->_data = "B";
		//_root->_lChild->_parent = _root;

		//_root->_rChild = new TreeNode<string>();
		//_root->_rChild->_data = "C";
		//_root->_rChild->_parent = _root;

		//TreeNode<string>* lchild = _root->_lChild, *rchild = _root->_rChild;
		//lchild->_lChild = new TreeNode<string>();
		//lchild->_lChild->_data = "D";
		//lchild->_lChild->_parent = lchild;

		//lchild->_rChild = new TreeNode<string>();
		//lchild->_rChild->_data = "E";
		//lchild->_rChild->_parent = lchild;

		//rchild->_lChild = new TreeNode<string>();
		//rchild->_lChild->_data = "F";
		//rchild->_lChild->_parent = rchild;

		//TreeNode<string>* temp = rchild->_lChild;
		//temp->_rChild = new TreeNode<string>();
		//temp->_rChild->_data = "I";
		//temp->_rChild->_parent = temp;

		//temp = lchild->_rChild;
		//temp->_lChild = new TreeNode<string>();
		//temp->_lChild->_data = "G";
		//temp->_lChild->_parent = temp;

		//temp->_rChild = new TreeNode<string>();
		//temp->_rChild->_data = "H";
		//temp->_rChild->_parent = temp;
	}
	virtual ~BinaryTree(){
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
	}

	// traversal
	void post_order_recursion(std::vector<T>& visitData) const {
		visitData.clear();
		if(_root)
			_root->post_order(visitData);
	}
	void post_order_iteration(std::vector<T>& visitData) const {
		visitData.clear();
		if (_root) {
			std::stack<TreeNode<T>*> stack;
			TreeNode<T>* prev = nullptr;
			stack.push(_root);
			while (!stack.empty()) {
				TreeNode<T>* now = stack.top();
				if (now->_parent == prev) {
					if (now->_lChild == nullptr && now->_rChild == nullptr) {
						visitData.push_back(now->_data);
						stack.pop();
					}
					else {
						if (now->_rChild)
							stack.push(now->_rChild);
						if (now->_lChild)
							stack.push(now->_lChild);
						prev = now;
					}
				}
				else {
					visitData.push_back(now->_data);
					prev = now->_parent;
					stack.pop();
				}
			}
		}
	}

	void pre_order_recursion(std::vector<T>& visitData) const {
		visitData.clear();
		if (_root)
			_root->pre_order(visitData);
	}
	void pre_order_iteration(std::vector<T>& visitData) const {
		visitData.clear();
		if (_root) {
			std::stack<TreeNode<T>*> stack;
			TreeNode<T>* now = _root;
			while (now) {
				if (now->_rChild)
					stack.push(now->_rChild);
				visitData.push_back(now->_data);
				now = now->_lChild;
				if (now == nullptr && !stack.empty()) {
					now = stack.top();
					stack.pop();
				}
			}
		}
	}

	// 這就是BST排序的traversal原理
	void in_order_recursion(std::vector<T>& visitData) const {
		visitData.clear();
		if (_root)
			_root->in_order(visitData);
	}

	void level_order(std::vector<T>& visitData) const {
		visitData.clear();
		std::queue<TreeNode<T>*> queue;
		if (_root) {
			queue.push(_root);
			while (!queue.empty()) {
				TreeNode<T>* temp = queue.front();
				queue.pop();
				visitData.push_back(temp->_data);
				if (temp->_lChild) {
					queue.push(temp->_lChild);
				}
				if (temp->_rChild) {
					queue.push(temp->_rChild);
				}
			}
		}
	}

	// iterator
	class iterator {
		friend class BinaryTree;
	public:
		iterator(){}
		iterator(TreeNode<T>* node, TreeNode<T>* root):_node(node), _root(root) {}
		~iterator(){}

		iterator& operator++ () { // ++i InorderSuccessor()
			if (_node->_rChild) {
				_node = leftmost(_node->_rChild);
			}
			else {
				TreeNode<T> *successor = _node->_parent;
				while ((successor != nullptr) && (successor->_rChild == _node)) { // 直到curNode來自parent的左邊
					_node = successor;
					successor = successor->_parent;
				}
				_node = successor;
			}
			return *this;
		}

		iterator operator++(int) { //i++
			iterator temp(*this);
			++(*this);
			return temp;
		}

		iterator& operator--() { // --i // InorderPredecessor()
			if (_node == nullptr) { //dummy end
				_node = rightmost(_root);
			}
			else {
				if (_node->_lChild) {
					_node = rightmost(_node->_lChild);
				}
				else {
					TreeNode<T>* predecessor = _node->_parent;
					while (predecessor != nullptr && predecessor->_lChild == _node) {// 直到curNode來自parent的右邊
						_node = predecessor;
						predecessor = _node->_parent;
					}
					_node = predecessor;
				}
			}
			return *this;
		}

		iterator operator--(int) { //i--
			iterator temp(*this);
			--(*this);
			return temp;
		}

		inline bool operator!= (const iterator& it) const {
			return _node != it._node;
		}

		inline bool operator==(const iterator& it) const {
			return _node == it._node;
		}

		inline T& operator*() {
			return _node->_data;
		}

		inline const T& operator*() const {
			return _node->_data;
		}

	private:
		TreeNode<T> *_node = nullptr, *_root = nullptr;

		TreeNode<T>* leftmost(TreeNode<T>* current) {
			while (current->_lChild) {
				current = current->_lChild;
			}
			return current;
		}

		TreeNode<T>* rightmost(TreeNode<T>* current) {
			while (current->_rChild) {
				current = current->_rChild;
			}
			return current;
		}
	};

	iterator begin() const {
		TreeNode<T>* temp = _root;
		if (_root) {
			while (!(temp->_lChild == nullptr)) {
				temp = temp->_lChild;
			}
		}
		return iterator(temp, _root);
	}

	iterator end() const {
		return iterator(nullptr, _root);
	}

	bool erase(const iterator& pos) {
		if (pos != end() && pos._root == _root) {
			TreeNode<T>* curNode = pos._node;
			if (curNode->_lChild == nullptr && curNode->_rChild == nullptr) { // 沒有小孩
				if (curNode->_parent == nullptr) // if curNode == _root
				{
					_root = nullptr;
				}
				else {
					cutRelation(curNode->_parent, curNode);
				}
				delete curNode;
			}
			else if (curNode->_lChild != nullptr && curNode->_rChild != nullptr) { // 兩邊都有小孩
				iterator it = pos;
				TreeNode<T>* successor = (++it)._node;
				curNode->_data = successor->_data;
				erase(it);
			}
			else { // 只有一邊有
				if (curNode->_parent == nullptr) // if curNode == _root
				{
					TreeNode<T>* onlyChild = nullptr;
					if (curNode->_lChild)
						onlyChild = curNode->_lChild;
					else
						onlyChild = curNode->_rChild;
					delete curNode;
					_root = onlyChild;
					onlyChild->_parent = nullptr;
				}
				else {
					TreeNode<T>* parent = curNode->_parent, *onlyChild = nullptr;
					if (curNode->_lChild)
						onlyChild = curNode->_lChild;
					else
						onlyChild = curNode->_rChild;

					if (parent->_lChild == curNode) 
						linkNode(parent, onlyChild, LEFT_WAY);
					else 
						linkNode(parent, onlyChild, RIGHT_WAY);
					delete curNode;
				}
			}
			return true;
		}
		return false;
	}

protected:
	enum LinkWay {
		LEFT_WAY,
		RIGHT_WAY,
		TOT_WAY
	};

	TreeNode<T> *_root = nullptr;

	TreeNode<T>* leftmost(TreeNode<T>* current) {
		while (current->_lChild) {
			current = current->_lChild;
		}
		return current;
	}

	TreeNode<T>* rightmost(TreeNode<T>* current) {
		while (current->_rChild) {
			current = current->_rChild;
		}
		return current;
	}

	void linkNode(TreeNode<T>* parent, TreeNode<T>* child, int way) {
		if (way == LEFT_WAY) {
			parent->_lChild = child;
			child->_parent = parent;
		}
		else if (way == RIGHT_WAY) {
			parent->_rChild = child;
			child->_parent = parent;
		}
	}

	void cutRelation(TreeNode<T>* parent, TreeNode<T>* child) {
		if (parent->_lChild == child) {
			parent->_lChild = nullptr;
		}
		else if (parent->_rChild == child) {
			parent->_rChild = nullptr;
		}
	}
};
