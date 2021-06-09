#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	long long M; cin >> M;	// 조카 수
	long long N; cin >> N;	// 과자 수
	vector<long long> length;	// 과자 길이

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		length.push_back(n);
	}

	long long max_length = *max_element(length.begin(), length.end());

	/*
	 1 ~ max_length 중 가능한 제일 긴 길이를 binary search
	 result의 default는 0
	*/

	long long low = 1, high = max_length, mid;
	long long result = 0;

	while (low <= high) {
		mid = (low + high) / 2;

		long long cnt = 0;
		for (long long l : length)
			cnt += l / mid;

		if (cnt >= M) {
			result = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << result << endl;
}
