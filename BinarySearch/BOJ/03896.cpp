#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

const int MAX_PRIME = 1299709;

int main() {
	bool isPrime[MAX_PRIME + 1];
	for (int i = 0; i <= MAX_PRIME; isPrime[i++] = true);

	// 에라토스테네스의 체
	for (int i = 3; i <= MAX_PRIME; i++) {
		if (!isPrime[i]) continue;
		if (i % 2 == 0) {
			isPrime[i] = false;
			continue;
		}

		for (int j = i * 2; j <= MAX_PRIME; j += i)
			isPrime[j] = false;
	}

	vector<int> primes;	// 소수만 모아놓은 벡터
	for (int i = 2; i <= MAX_PRIME; i++)
		if (isPrime[i]) primes.push_back(i);

	int T; cin >> T;	// 테케 수

	for (int tc = 0; tc < T; tc++) {
		int k; cin >> k;

		// 소수일 때
		if (isPrime[k]) cout << 0 << endl;
		else {
			// binary search
			int low = 0, high = min(k, 99999), mid;

			while (low < high) {
				mid = (low + high) / 2;

				if (k > primes[mid]) low = mid + 1;
				else high = mid;
			}

			cout << primes[low] - primes[low - 1] << endl;
		}
	}
}
