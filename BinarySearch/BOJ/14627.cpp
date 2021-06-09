#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	long long S; cin >> S;	// 파 개수
	long long C; cin >> C;	// 파닭 수
	vector<long long> L;	// 파 길이

	for (long long i = 0; i < S; i++) {
		long long l; cin >> l;
		L.push_back(l);
	}

	/*
	 (1 ~ 제일 짧은 파 길이) 사이에서
	 가능한 제일 크게 자를 수 있는 길이를 binary search
	 result: 그 때 라면에 넣을 수 있는 파의 양
	*/

	long long low = 1, high = *max_element(L.begin(), L.end()), mid;
	long long result;

	while (low <= high) {
		mid = (low + high) / 2;

		long long cnt = 0, rest = 0;
		for (int l : L) {
			cnt += l / mid;
			rest += l % mid;
		}

		if (cnt >= C) {
			rest += (cnt - C) * mid;
			result = rest;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << result << endl;
}
