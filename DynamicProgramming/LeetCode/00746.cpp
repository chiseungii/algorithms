class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> DP = { 0, cost[0] };

		for (int i = 1; i < cost.size(); i++)
			DP.push_back(min(DP[i], DP[i - 1]) + cost[i]);

		return min(DP.back(), DP[DP.size() - 2]);
	}
};
