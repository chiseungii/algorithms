class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> DP = { 1 };

		for (int i = 1; i < nums.size(); i++) {
			int max = 0;

			for (int j = 0; j < i; j++)
				if (nums[j]<nums[i] && DP[j]>max)
					max = DP[j];

			DP.push_back(max + 1);
		}

		return *max_element(DP.begin(), DP.end());
	}
};
