#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	unsigned long long n; cin >> n;

	if (n == 0) cout << 0 << endl;
	else if (n == 1) cout << 1 << endl;
	else {
		// binary search
		unsigned long long low = 1, high = min(n, (unsigned long long)3037000500);
		unsigned long long mid, result;

		while (low <= high) {
			mid = (low + high) / 2;

			if (mid * mid >= n) {
				result = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}

		cout << result << endl;
	}
}
