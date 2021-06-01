#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result = { -1, -1 };	// 결과 초기화

		/*
		 시작점 찾기
		*/

		int low = 0, high = nums.size() - 1, mid;

		while (low <= high) {
			mid = (low + high) / 2;

			if (nums[mid] == target) {
				result[0] = mid;
				high = mid - 1;
			}
			else if (target > nums[mid])
				low = mid + 1;
			else high = mid - 1;
		}

		/*
		 끝점 찾기
		*/

		low = 0, high = nums.size() - 1;

		while (low <= high) {
			mid = (low + high) / 2;

			if (nums[mid] == target) {
				result[1] = mid;
				low = mid + 1;
			}
			else if (target > nums[mid])
				low = mid + 1;
			else high = mid - 1;
		}

		return result;
	}
};
