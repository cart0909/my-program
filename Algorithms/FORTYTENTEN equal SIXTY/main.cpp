#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	random_device rd;
	mt19937 gen(rd());
	std::uniform_int_distribution<> disforn(0, 2), disforv(0, 9);

	int F = -1, O = -1, R = -1, T = -1, Y = -1, E = -1, N = -1, S = -1, I = -1, X = -1;
	int n0 = 0, n1 = 1, n2 = -1;
	vector<bool> table;
	for (int i = 0; i < 10; ++i)
		table.push_back(false);
	clock_t t0 = clock();

	do {
		for (auto& it : table)
			it = false;

		N = 5 * n0;
		table[N] = true;

		E = (10 * n1 - n0)/2;
		table[E] = true;

		n2 = disforn(gen);
		do {
			I = disforv(gen);
			if (table[I] != true){
				table[I] = true;
				break;
			}
		} while (1);

		do {
			S = disforv(gen);
			if (table[S] != true) {
				table[S] = true;
				break;
			}
		} while (1);

		do {
			X = disforv(gen);
			if (table[X] != true) {
				table[X] = true;
				break;
			}
		} while (1);

		do {
			T = disforv(gen);
			if (table[T] != true) {
				table[T] = true;
				break;
			}
		} while (1);

		O = I - n2 + 10;
		try {
			if (table.at(O) == false)
				table.at(O) = true;
			else
				continue;
		}
		catch (...) {
			continue;
		}
		F = S - 1;
		try {
			if (table.at(F) == false)
				table.at(F) = true;
			else
				continue;
		}
		catch (...) {
			continue;
		}
		R = 10 * n2 - n1 + X - 2 * T;
		try {
			if (table.at(R) == false)
				table.at(R) = true;
			else
				continue;
		}
		catch (...) {
			continue;
		}

		for (int i = 0; i < 10; ++i) {
			if (table[i] == false) {
				table[i] = true;
				Y = i;
				break;
			}
		}

		for (auto& it : table) {
			if (it == false)
				continue;
		}

		if ((10000 * F + 1000 * O + 100 * R + 10 * T + Y + 200 * T + 20 * E + 2 * N) == (10000 * S + 1000 * I + 100 * X + 10 * T + Y))
			break;
	} while (1);

	cout << 10000 * F + 1000 * O + 100 * R + 10 * T + Y << endl;
	cout << 100 * T + 10 * E + N << endl;
	cout << (10000 * S + 1000 * I + 100 * X + 10 * T + Y) << endl;
	cout << "spend:" << clock() - t0 << " (ms)" << endl;
	system("pause");
	return 0;
}