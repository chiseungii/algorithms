class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int> DP = { 0 };
		int min_price = prices[0];

		for (int i = 1; i < prices.size(); i++) {
			DP.push_back(max(DP[i - 1], prices[i] - min_price));
			if (prices[i] < min_price) min_price = prices[i];
		}

		return DP.back();
	}
};
