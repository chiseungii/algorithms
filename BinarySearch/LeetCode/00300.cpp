class Solution {
private:
	int binarySearch(vector<int> v, int n) {
		// v가 비었을 때
		if (v.empty()) return 0;
		// 맨 앞 순서
		if (n <= v[0]) return 0;
		// 맨 뒤 순서
		if (n > v.back()) return v.size();

		int low = 0, high = v.size() - 1, mid;

		while (low < high) {
			mid = (low + high) / 2;

			if (n <= v[mid]) high = mid;
			else low = mid + 1;
		}

		return low;
	}

public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> DP;
		int len = 0;

		for (int n : nums) {
			int index = binarySearch(DP, n);

			// push해야 할 경우
			if (index >= DP.size()) {
				DP.push_back(n);
				len++;
			}
			else DP[index] = n;
		}

		return len;
	}
};
