class Solution {
public:
	int climbStairs(int n) {
		vector<int> DP = { 1, 1 };

		for (int i = 2; i <= n; i++)
			DP.push_back(DP[i - 2] + DP[i - 1]);

		return DP[n];
	}
};
