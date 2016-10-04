#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Q103 {
	typedef pair<int, vector<int>> Data;

	struct DataComp
	{
		bool operator()(Data* ldPtr,Data* rdPtr) const{
			const Data &ld = *ldPtr, &rd = *rdPtr;
			int i = 0, n = 0;
			for (i = 0, n = ld.second.size(); i < n; ++i) {
				if (ld.second[i] <= rd.second[i])
					return true;
			}
			return false; // swap
		}
	};

public:

	void loop() {
		int num = 0, dim = 0, token;
		while (cin >> num >> dim) {
			_dataList.clear();
			for (int i = 0; i < num; ++i) {
				double norm = 0.0;
				Data* temp = new Data(i + 1, vector<int>());
				temp->second.reserve(dim);
				for (int i = 0; i < dim; ++i) {
					cin >> token;
					temp->second.push_back(token);
				}
				sort(temp->second.begin(), temp->second.end(), less<int>());
				_dataList.push_back(temp);
			}
			//sort(_dataList.begin(), _dataList.end(), DataComp());

			for (int i = 0, n = _dataList.size(); i < n - 1; ++i) {
				for (int j = i; j < n; ++j) {
					if (!DataComp()(_dataList[i], _dataList[j])) {
						Data* temp = _dataList[i];
						_dataList[i] = _dataList[j];
						_dataList[j] = temp;
					}
				}
			}

			//for (auto& it : _dataList) {
			//	cout << it->first << ": ";
			//	for (auto&j : it->second) {
			//		cout << j << " ";
			//	}
			//	cout << endl;
			//}

			//cout << endl;
			vector<int> idSeq;
			cout << lis(idSeq) << endl;
			for (auto& it : idSeq) {
				if (it == idSeq.back())
					cout << _dataList[it]->first;
				else
					cout << _dataList[it]->first << " ";
			}
			cout << endl;
		}
	}

private:

	int lis(vector<int>& idSeq) {
		vector<int> best, parent;
		for (int i = 0, n = _dataList.size(); i < n; ++i) {
			best.push_back(1);
			parent.push_back(i);
		}

		for (int i = 1, n = _dataList.size(); i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (!DataComp()(_dataList[i], _dataList[j]) && best[i] < best[j] + 1) {
					best[i] = best[j] + 1;
					parent[i] = j;
				}
			}
		}

		int index = 0;
		int max = 0;
		for (int i = 0, n = _dataList.size(); i < n; ++i)
		{
			if (max < best[i])
			{
				max = best[i];
				index = i;
			}
		}
		idSeq.clear();
		stack<int> idStack;
		while (index != parent[index]) {
			idStack.push(index);
			index = parent[index];
		}
		idStack.push(index);
		while (!idStack.empty()) {
			idSeq.push_back(idStack.top());
			idStack.pop();
		}

		return max;
	}

	vector<Data*> _dataList;
};

int main() {
	//§ï¦ê¬y
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	Q103 demo;
	demo.loop();

	return 0;
}