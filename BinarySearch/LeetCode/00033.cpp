#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

#define MIN_INT -2147483648
#define MAX_INT 2147483647

class Solution {
public:
	int search(vector<int>& nums, int target) {
		/*
		 k 찾기
		*/

		int k = 0;

		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				k = nums.size() - i - 1;
				break;
			}
		}

		// 배열 원래대로 해놓기
		for (int i = 0; i < k; i++) {
			nums.insert(nums.begin(), nums.back());
			nums.pop_back();
		}

		/*
		 binary search
		*/

		int low = 0, high = nums.size() - 1, mid;

		while (low <= high) {
			mid = (low + high) / 2;

			if (nums[mid] == target) {
				mid -= k;
				return mid >= 0 ? mid : mid + nums.size();
			}
			else if (target > nums[mid])
				low = mid + 1;
			else high = mid - 1;
		}

		return -1;
	}
};
