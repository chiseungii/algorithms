#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int binarySearch(vector<int> v, int n) {
	if (n <= v[0]) return 0;
	if (n > v.back()) return v.size();

	int low = 0, high = v.size() - 1, mid;

	while (low < high) {
		mid = (low + high) / 2;

		if (n <= v[mid]) high = mid;
		else low = mid + 1;
	}

	return low;
}

int main() {
	int T; cin >> T;	// 테케 수

	for (int tc = 0; tc < T; tc++) {
		int N; cin >> N;	// A의 개수
		int M; cin >> M;	// B의 개수
		vector<int> A, B;

		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			A.push_back(a);
		}
		for (int i = 0; i < M; i++) {
			int b; cin >> b;
			B.push_back(b);
		}

		// 두 벡터 정렬
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		/*
		 A의 원소들이 B에 낄 자리를 binary search
		*/

		int cnt = 0;

		for (int a : A)
			cnt += binarySearch(B, a);

		cout << cnt << endl;
	}
}
