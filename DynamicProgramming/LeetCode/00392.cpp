class Solution {
public:
	bool isSubsequence(string s, string t) {
		int index = 0;
		vector<int> DP = { -1 };

		for (int i = 0; i < t.length(); i++) {
			if (index >= s.length())
				DP.push_back(DP[i]);
			else if (t[i] == s[index])
				DP.push_back(index++);
			else
				DP.push_back(DP[i]);
		}

		return DP.back() == (s.length() - 1);
	}
};
