#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

int main() {
	int N; cin >> N;	// 용액 수
	vector<int> nums;	// 용액 특성값

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end());

	// 1. 모두 양수인 경우
	if (nums[0] > 0)
		cout << nums[0] << ' ' << nums[1] << endl;
	// 2. 모두 음수인 경우
	else if (nums.back() < 0)
		cout << nums[nums.size() - 2] << ' ' << nums.back() << endl;
	// 3. 양수, 음수 둘 다 있는 경우
	else {
		/*
		 양쪽 끝에서 시작해서 합의 최소값을 찾음
		*/

		int min_sum = 2000000010, number[2];
		int left = 0, right = nums.size() - 1;

		while (left < right) {
			int tmp_sum = nums[left] + nums[right];
			// 최소값보다 작으면 저장
			if (abs(tmp_sum) < min_sum) {
				min_sum = abs(tmp_sum);
				number[0] = nums[left];
				number[1] = nums[right];
			}

			if (tmp_sum < 0) left++;
			else right--;
		}

		cout << number[0] << ' ' << number[1] << endl;
	}
}
