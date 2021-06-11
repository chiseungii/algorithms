#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	long long N; cin >> N;	// N x N
	long long k; cin >> k;

	/*
	 1 ~ N*N 중에서 가능한 수를
	 count를 이용해 binary search
	*/

	long long low = 1, high = N * N;
	long long mid, result;

	while (low <= high) {
		mid = (low + high) / 2;

		// mid / 1 ~ N 를 모두 더함
		long long cnt = 0;

		for (long long i = 1; i <= N && i <= mid; i++)
			cnt += min(mid / i, N);

		// cnt < k : 불가능 -> 찾는 수는 더 큼
		if (cnt < k) low = mid + 1;
		else {
			result = mid;
			high = mid - 1;
		}
	}

	cout << result << endl;
}
