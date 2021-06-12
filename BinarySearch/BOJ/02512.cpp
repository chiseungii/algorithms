#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	int N; cin >> N; // 지방 수
	vector<int> prices;	// 요청 예산

	for (int i = 0; i < N; i++) {
		int p; cin >> p;
		prices.push_back(p);
	}

	int M; cin >> M;	// 총 예산

	// binary search
	int low = 1, high = *max_element(prices.begin(), prices.end());
	int mid, result;

	while (low <= high) {
		mid = (low + high) / 2;

		int sum = 0;
		for (int price : prices)
			sum += min(price, mid);

		// 가능 -> 상한액 더 올림
		if (sum <= M) {
			result = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << result << endl;
}
