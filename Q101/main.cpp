#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Q101 {
	typedef vector<vector<int>> Box;
	typedef pair<int, int> Pos;
public:
	Q101(int numBox = 0) {
		_box.reserve(numBox);
		for (int i = 0; i < numBox; ++i) {
			_box.push_back(vector<int>());
			_box[i].reserve(numBox);
			_box[i].push_back(i);
			_pos.push_back(Pos(i, 0));
		}
	}
	~Q101() {}

	void loop(){
		string line, token;
		while (getline(cin, line)) {
			vector<string> seg;
			istringstream is(line);
			while (is >> token) {
				seg.push_back(token);
			}

			if (seg.size() == 1) {
				if (seg[0] == "quit") {
					break;
				}
			}
			else if (seg.size() == 4) {
				if (seg[0] == "move") {
					if (seg[2] == "onto") {
						try {
							moveOnto(stoi(seg[1]), stoi(seg[3]));
						}
						catch (...) {

						}
					}
					else if (seg[2] == "over") {
						try {
							moveOver(stoi(seg[1]), stoi(seg[3]));
						}
						catch (...) {

						}
					}
				}
				else if (seg[0] == "pile") {
					if (seg[2] == "onto") {
						try {
							pileOnto(stoi(seg[1]), stoi(seg[3]));
						}
						catch (...) {

						}
					}
					else if (seg[2] == "over") {
						try {
							pileOver(stoi(seg[1]), stoi(seg[3]));
						}
						catch (...) {

						}
					}
				}
			}
		}
	}

	void show() {
		for (int i = 0, n = _box.size(); i < n; ++i) {
			if (_box[i].empty()) {
				cout << i << ":" << endl;
			}
			else {
				cout << i << ": ";
				for (int j = 0, m = _box[i].size() - 1; j < m; ++j) {
					cout << _box[i][j] << " ";
				}
				cout << _box[i].back() << endl;
			}
		}
	}

	void moveOnto(int a, int b) {
		if (a == b || _pos[a].first == _pos[b].first)
			return;
		
		for (int i = _pos[a].second + 1, n = _box[_pos[a].first].size(); i < n; ++i) {
			int id = _box[_pos[a].first][i];
			_box[id].push_back(id);
			_pos[id] = Pos(id, _box[id].size()-1);
		}
		_box[_pos[a].first].resize(_pos[a].second);

		for (int i = _pos[b].second + 1, n = _box[_pos[b].first].size(); i < n; ++i) {
			int id = _box[_pos[b].first][i];
			_box[id].push_back(id);
			_pos[id] = Pos(id, _box[id].size() - 1);
		}
		_box[_pos[b].first].resize(_pos[b].second + 1);
		_box[_pos[b].first].push_back(a);
		_pos[a] = Pos(_pos[b].first, _box[_pos[b].first].size()-1);
	}

	void moveOver(int a, int b) {
		if (a == b || _pos[a].first == _pos[b].first)
			return;

		for (int i = _pos[a].second + 1, n = _box[_pos[a].first].size(); i < n; ++i) {
			int id = _box[_pos[a].first][i];
			_box[id].push_back(id);
			_pos[id] = Pos(id, _box[id].size() - 1);
		}
		_box[_pos[a].first].resize(_pos[a].second);

		_box[_pos[b].first].push_back(a);
		_pos[a] = Pos(_pos[b].first, _box[_pos[b].first].size() - 1);
	}

	void pileOnto(int a, int b) {
		if (a == b || _pos[a].first == _pos[b].first)
			return;
		for (int i = _pos[b].second + 1, n = _box[_pos[b].first].size(); i < n; ++i) {
			int id = _box[_pos[b].first][i];
			_box[id].push_back(id);
			_pos[id] = Pos(id, _box[id].size() - 1);
		}
		_box[_pos[b].first].resize(_pos[b].second + 1);

		_box[_pos[b].first].insert(_box[_pos[b].first].end(), _box[_pos[a].first].begin()+_pos[a].second, _box[_pos[a].first].end());
		_box[_pos[a].first].resize(_pos[a].second);
		for (int i = _pos[b].second + 1, n = _box[_pos[b].first].size(); i < n; ++i) {
			int id = _box[_pos[b].first][i];
			_pos[id] = Pos(_pos[b].first, i);
		}
	}

	void pileOver(int a, int b) {
		if (a == b || _pos[a].first == _pos[b].first)
			return;
		_box[_pos[b].first].insert(_box[_pos[b].first].end(), _box[_pos[a].first].begin()+_pos[a].second, _box[_pos[a].first].end());
		_box[_pos[a].first].resize(_pos[a].second);
		for (int i = _pos[b].second + 1, n = _box[_pos[b].first].size(); i < n; ++i) {
			int id = _box[_pos[b].first][i];
			_pos[id] = Pos(_pos[b].first, i);
		}
	}
private:
	Box _box;
	vector<Pos> _pos;
};

int main() {
	//§ï¦ê¬y
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int num;
	while (cin >> num){
		if (num > 0 && num < 25) {
			Q101 demo(num);
			demo.loop();
			demo.show();
		}
	}
	return 0;
}