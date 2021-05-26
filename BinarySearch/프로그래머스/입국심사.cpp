#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
	long long max_time = *max_element(times.begin(), times.end());	// 가장 오래 걸리는 시간
	long long left = 0, right = max_time * n;
	long long result = right + 1;

	while (left < right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (int i = 0; i < times.size(); i++)
			sum += mid / (long long)times[i];

		// 충분히 가능한 경우
		if (sum >= n) {
			result = mid;
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return result;
}
