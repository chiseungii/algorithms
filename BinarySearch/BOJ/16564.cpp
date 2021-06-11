#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	long long N; cin >> N;	// 캐릭터 수
	long long K; cin >> K;	// 레벨 한계치
	vector<long long> X;	// 각 캐릭터 레벨

	for (long long i = 0; i < N; i++) {
		long long x; cin >> x;
		X.push_back(x);
	}

	/*
	 low: 현재 목표 레벨
	 high: low + K
	 가능한 목표 레벨의 최대값을 binary search
	*/

	long long low = *min_element(X.begin(), X.end());
	long long high = low + K, mid, result;

	while (low <= high) {
		mid = (low + high) / 2;

		// 목표 레벨을 mid로 올리는 데 필요한 레벨의 합
		long long sum = 0;
		for (long long x : X)
			sum += max(mid - x, (long long)0);

		// sum <= K : 가능하다 -> 목표 레벨 더 높게
		if (sum <= K) {
			result = mid;
			low = mid + 1;
		}
		// 불가능 -> 목표 레벨 더 낮게
		else high = mid - 1;
	}

	cout << result << endl;
}
