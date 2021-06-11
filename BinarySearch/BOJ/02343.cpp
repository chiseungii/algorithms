#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	int N; cin >> N;	// 레슨 개수
	int M; cin >> M;	// 블루레이 개수
	vector<int> lessons;	// 레슨 길이

	for (int i = 0; i < N; i++) {
		int lesson; cin >> lesson;
		lessons.push_back(lesson);
	}

	int sum_lesson = 0;	// 레슨 총 길이
	for (int i = 0; i < N; sum_lesson += lessons[i++]);

	/*
	 1 ~ sum_lesson 중 가능한 블루레이 길이의
	 최소값을 binary search
	*/

	int low = 1, high = sum_lesson, mid;
	int result;

	while (low <= high) {
		mid = (low + high) / 2;

		// mid 길이로 만들 수 있는 블루레이 개수
		int cnt = 1, sum = 0;
		bool flag = true;

		for (int i = 0; i < N; i++) {
			if (lessons[i] > mid) {
				flag = false;
				break;
			}

			sum += lessons[i];

			if (sum > mid) {
				sum = lessons[i];
				cnt++;
			}
		}

		if (!flag) {
			low = mid + 1;
			continue;
		}

		// cnt <= M : 가능 -> 블루레이 길이 줄임
		if (cnt <= M) {
			result = mid;
			high = mid - 1;
		}
		// 불가능 -> 블루레이 길이 늘임
		else low = mid + 1;
	}

	cout << result << endl;
}
