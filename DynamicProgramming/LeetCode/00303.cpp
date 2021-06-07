class NumArray {
private:
	vector<int> DP;

public:
	NumArray(vector<int>& nums) {
		DP.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
			DP.push_back(DP[i - 1] + nums[i]);
	}

	int sumRange(int left, int right) {
        if (left == 0) return DP[right];
		return DP[right] - DP[left - 1];
	}
};
