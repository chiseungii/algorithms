#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	long long X; cin >> X;	// 게임 횟수
	long long Y; cin >> Y;	// 이긴 게임
	long long Z = (Y * 100) / X;	// 승률

	// X번 더 이겨도 승률이 변하지 않을 경우
	if (((Y + X) * 100) / (2 * X) == Z) cout << -1 << endl;
	else {
		/*
		 1 ~ X 중에서 승률이 변하는 게임 횟수를 binary search
		*/

		long long low = 1, high = X, mid;
		long long result;

		while (low <= high) {
			mid = (low + high) / 2;
			long long new_Z = ((Y + mid) * 100) / (X + mid);

			if ((new_Z - Z) > 0) {
				result = mid;
				high = mid - 1;
			}
			else low = mid + 1;
		}

		cout << result << endl;
	}
}
