class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> DP = { nums[0] };
		int result = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			DP.push_back(max(nums[i], DP[i - 1] + nums[i]));
			if (DP[i] > result) result = DP[i];
		}

		return max(result, DP[DP.size() - 1]);
	}
};
