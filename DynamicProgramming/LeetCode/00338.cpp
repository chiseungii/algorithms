class Solution {
public:
	vector<int> countBits(int n) {
		/*
		 DP[i]
		 i가 홀수: DP[i - 1] + 1
		 i가 짝수: DP[i / 2]
		*/

		if (n == 0) return { 0 };
		if (n == 1) return { 0, 1 };
		
		vector<int> DP = { 0, 1, 1 };

		for (int i = 3; i <= n; i++) {
			if (i % 2) DP.push_back(DP[i - 1] + 1);
			else DP.push_back(DP[i / 2]);
		}

		return DP;
	}
};
