class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		vector<vector<int>> DP;
		vector<vector<int>> sum; // 전체 합

		// 맨 윗줄
		vector<int> first = { matrix[0][0] };
		for (int i = 1; i < matrix[0].size(); i++)
			first.push_back(first[i - 1] + matrix[0][i]);

		DP.push_back(first);
		sum.push_back(first);

		// 두 번째 줄부터
		for (int i = 1; i < matrix.size(); i++) {
			vector<int> tmp_DP = { DP[i - 1][0] + matrix[i][0] };
			vector<int> tmp_sum = { sum[i - 1][0] + matrix[i][0] };

			for (int j = 1; j < matrix[i].size(); j++) {
				// 합
				int n = tmp_sum[j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + matrix[i][j];
				tmp_sum.push_back(n);

				// DP 계산
				n = tmp_DP[j - 1] + DP[i - 1][j] - DP[i - 1][j - 1] + matrix[i][j];
				int min_square = min(i, j) + 1;

				if (min_square > 1) {
					for (int k = 2; k <= min_square; k++) {
						// 왼쪽 위 모서리 구하기
						int c_i = i - (k - 1);
						int c_j = j - (k - 1);

						// 왼쪽 위부터 오른쪽 아래까지 부분합이랑 비교
						int s = tmp_sum[j];
						if (c_i == 0 && c_j == 0);
						else if (c_i == 0 || c_j == 0) {
							if (c_i == 0) s -= tmp_sum[c_j - 1];
							else s -= sum[c_i - 1][j];
						}
						else {
							s -= tmp_sum[c_j - 1];
							s -= sum[c_i - 1][j];
							s += sum[c_i - 1][c_j - 1];
						}

						if (k * k == s) n++;
					}
				}

				tmp_DP.push_back(n);
			}

			// 업뎃
			DP.push_back(tmp_DP);
			sum.push_back(tmp_sum);
		}

		return DP.back().back();
	}
};
