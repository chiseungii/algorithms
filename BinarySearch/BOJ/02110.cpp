#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	long long N; cin >> N;	// 집 개수
	long long C; cin >> C;	// 공유기 개수
	vector<long long> X;	// 집 좌표

	for (long long i = 0; i < N; i++) {
		long long x; cin >> x;
		X.push_back(x);
	}
	sort(X.begin(), X.end());

	long long max_interval = X.back() - X[0];

	/*
	 1 ~ max_interval 사이에서 가능한 최대값을 binary search
	*/

	long long low = 1, high = max_interval, mid;
	long long result;

	while (low <= high) {
		mid = (low + high) / 2;

		// 최소한 mid 간격으로 세울 수 있는 공유기 수
		long long cnt = 1, locate = X[0];

		for (long long i = 1; i < X.size(); i++) {
			if (X[i] - locate >= mid) {
				cnt++;
				locate = X[i];
			}
		}

		if (cnt < C) high = mid - 1;
		else if (cnt >= C) {
			result = mid;
			low = mid + 1;
		}
		// else low = mid + 1;
	}

	cout << result << endl;
}
