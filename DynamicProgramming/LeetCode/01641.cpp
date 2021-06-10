class Solution {
public:
	int countVowelStrings(int n) {
		if (n == 1) return 5;
		if (n == 2) return 15;

		int cnt[5] = { 1, 1, 1, 1, 1 };

		for (int i = 3; i <= n; i++) {
			for (int j = 1; j < 5; j++)
				cnt[j] = cnt[j - 1] + cnt[j];
		}

		int sum = 0;
		for (int i = 0; i < 5; i++)
			sum += (5 - i) * cnt[i];

		return sum;
	}
};
