class Solution {
private:
	int count(vector<int> nums, int n) {
		int cnt = 0;
		for (int num : nums)
			if (num <= n) cnt++;

		return cnt;
	}

public:
	int findDuplicate(vector<int>& nums) {
		/*
		 1 ~ n 까지 binary search
		 mid보다 작거나 같은 수의 개수와 mid를 비교
		*/

		int low = 1, high = nums.size() - 1, mid;
		int result = -1;

		while (low <= high) {
			mid = (low + high) / 2;

			if (count(nums, mid) <= mid)
				low = mid + 1;
			else {
				result = mid;
				high = mid - 1;
			}
		}

		return result;
	}
};
