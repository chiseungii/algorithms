#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	int T; cin >> T;	// 테케 수

	for (int tc = 0; tc < T; tc++) {
		int N; cin >> N;	// 참가자 수
		int X; cin >> X;	// 트랙 길이(m)
		int Y; cin >> Y;	// 부스터 한계치
		
		vector<int> V;	// 속도
		for (int i = 0; i < N; i++) {
			int Vi; cin >> Vi;
			V.push_back(Vi);
		}

		vector<double> sec;	// 참가자들 완주 시간
		for (int Vi : V)
			sec.push_back((double)X / (double)Vi);

		double min_sec = *min_element(sec.begin(), sec.end());	// 나 빼고 1등

		// min_sec가 내 기록이면 바로 0 리턴
		if (min_sec == sec.back()) {
			cout << 0 << endl;
			continue;
		}

		/*
		 0 ~ Y 중에서 가능한 최소값을 binary search
		*/

		int low = 0, high = Y, mid;
		int result = -1;

		while (low <= high) {
			mid = (low + high) / 2;

			double myTime = X - mid;
			myTime = myTime / (double)V.back() + 1;

			if (myTime >= min_sec) low = mid + 1;
			else {
				result = mid;
				high = mid - 1;
			}
		}

		cout << result << endl;
	}
}
