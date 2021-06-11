#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	long long N; cin >> N;	// 입국심사대 수
	long long M; cin >> M;	// 사람 수
	vector<long long> T;	// 심사 시간

	for (int i = 0; i < N; i++) {
		long long n; cin >> n;
		T.push_back(n);
	}
	sort(T.begin(), T.end());

	// 모든 사람이 가장 오래 걸리는 심사대에서 심사 받을 때
	long long max_time = M * T.back();

	/*
	 1 ~ max_time 중 가능한 최소값을 binary search
	*/

	long long low = 1, high = max_time, mid;
	long long result;

	while (low <= high) {
		mid = (low + high) / 2;

		// mid 시간 내에 검사할 수 있는 인원 수
		long long cnt = 0;
		for (long long t : T)
			cnt += mid / t;

		// M보다 같거나 많이 검사할 수 있으면
		// 총 검사 시간 줄여도 됨
		if (cnt >= M) {
			result = mid;
			high = mid - 1;
		}
		// M명 전부 검사 불가능
		// 총 검사 시간 늘려야 됨
		else low = mid + 1;
	}

	cout << result << endl;
}
