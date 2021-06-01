#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> nums;	// <nums1의 숫자, 개수>

		// 숫자 카운트
		for (int n : nums1) nums[n]++;

		vector<int> result;

		for (int n : nums2) {
			if (nums[n]) {
				result.push_back(n);
				nums[n]--;
			}
		}

		return result;
	}
};
