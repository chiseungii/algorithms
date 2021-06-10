#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	long long N; cin >> N;	// 아이들 수
	long long M; cin >> M;	// 색상 수
	vector<long long> jewels;	// 보석

	for (long long i = 0; i < M; i++) {
		long long m; cin >> m;
		jewels.push_back(m);
	}

	long long max_jewel = *max_element(jewels.begin(), jewels.end());

	/*
	 1 ~ max_jewel 중에서 가능한 질투심의 최소값을 binary search
	*/

	long long low = 1, high = max_jewel, mid;
	long long result = 0;

	while (low <= high) {
		mid = (low + high) / 2;

		long long cnt = 0;
		for (long long j : jewels)
			cnt += (j / mid) + (j % mid != 0);

		if (cnt <= N) {
			result = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}

	cout << result << endl;
}
