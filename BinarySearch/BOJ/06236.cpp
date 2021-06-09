#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int count(vector<int> v, int K) {
	int cnt = 0;
	int money = 0;

	for (int vi : v) {
		// 인출해도 모자르면 불가능
		if (K < vi) return -1;

		if (money < vi) {
			money = K;
			cnt++;
		}

		money -= vi;
	}

	return cnt;
}

int main() {
	int N; cin >> N;	// 돈 쓰는 날
	int M; cin >> M;	// 인출 가능한 횟수
	vector<int> money;	// 매일 쓸 돈

	for (int i = 0; i < N; i++) {
		int m; cin >> m;
		money.push_back(m);
	}

	int max_money = *max_element(money.begin(), money.end());
	int sum_money = 0;

	for (int m : money) sum_money += m;

	/*
	 1 ~ sum_money 중 가능한 제일 작은 액수를 binary search
	*/

	int low = 1, high = sum_money, mid;
	int K;

	while (low <= high) {
		mid = (low + high) / 2;
		int countK = count(money, mid);

		if (countK == -1 || countK > M)
			low = mid + 1;
		else {
			K = mid;
			high = mid - 1;
		}
	}

	cout << K << endl;
}
