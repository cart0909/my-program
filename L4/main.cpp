#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <cassert>
using namespace std;

int findKthValue(const vector<int>& x, const vector<int>& y, int K);
int findKthValue(const vector<int>::const_iterator& xbegin, const vector<int>::const_iterator& xend, const vector<int>::const_iterator& ybegin, const vector<int>::const_iterator& yend, int K);

int findKthValue(const vector<int>& x,const vector<int>& y, int K) {
	return findKthValue(x.cbegin(), x.cend(), y.cbegin(), y.cend(), K);
}

int findKthValue(const vector<int>::const_iterator& xbegin,const vector<int>::const_iterator& xend,const vector<int>::const_iterator& ybegin,const vector<int>::const_iterator& yend, int K) {
	int xsize = xend - xbegin, ysize = yend - ybegin;
	assert(K <= xsize + ysize && K > 0);
	if (xsize == 0) {
		return *(ybegin + K - 1);
	}
	else if (ysize == 0) {
		return *(xbegin + K - 1);
	}
	else {
		if (K == 1) {
			return min(*xbegin, *ybegin);
		}
		else {
			int kHalf = K / 2 - 1;
			if (kHalf < xsize && kHalf < ysize) {
				auto xkHalf = xbegin + kHalf, ykHalf = ybegin + kHalf;
				if (*xkHalf > *ykHalf) {
					return findKthValue(xbegin, xend, ykHalf+1, yend, K - (kHalf + 1));
				}
				else if (*xkHalf < *ykHalf) {
					return findKthValue(xkHalf+1, xend, ybegin, yend, K - (kHalf + 1));
				}
				else { // ==
					if (K % 2 == 0) {
						return *xkHalf;
					}
					else {
						return findKthValue(xkHalf + 1, xend, ykHalf + 1, yend, K - 2*(kHalf + 1));
					}
				}
			}
			else if (xsize <= kHalf) {
				auto ykHalf = ybegin + kHalf, xback = xend-1;
				if (*ykHalf >= *xback) {
					return findKthValue(xend, xend, ybegin, yend, K - xsize);
				}
				else {
					return findKthValue(xbegin, xend, ykHalf+1, yend, K - (kHalf + 1));
				}
			}
			else { //ysize <= kHalf
				auto xkHalf = xbegin + kHalf, yback = yend - 1;
				if (*xkHalf >= *yback) {
					return findKthValue(xbegin, xend, yend, yend, K - ysize);
				}
				else {
					return findKthValue(xkHalf+1, xend, ybegin, yend, K - (kHalf + 1));
				}
			}
		}
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int K = nums1.size() + nums2.size();
	if (K % 2 != 0) { // ©_¼Æ
		return (double)findKthValue(nums1, nums2, (K + 1) / 2);
	}
	else {
		return ((double)findKthValue(nums1, nums2, K / 2) + (double)findKthValue(nums1, nums2, K / 2 + 1))/2;
	}
}

int main() {
	//§ï¦ê¬y
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);

	vector<int> x, y;
	for (int i = 0, n = dis(gen); i < n; ++i) {
		x.push_back(dis(gen));
	}
	for (int i = 0, n = dis(gen); i < n; ++i) {
		y.push_back(dis(gen));
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	x = { 1, 2 };
	y = { 1, 2 };

	//cout << "[";
	//for (auto& it : x) {
	//	cout << it << " ,";
	//}
	//cout << "]" << endl;
	//cout << "[";
	//for (auto& it : y) {
	//	cout << it << " ,";
	//}
	//cout << "]" << endl;

	cout << findMedianSortedArrays(x, y) << endl;

	system("pause");
	return 0;
}