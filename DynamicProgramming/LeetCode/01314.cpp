class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int row = mat.size();	// 행 개수
		int col = mat[0].size();	// 열 개수

		// mat[i][j] = mat[0][0] ~ mat[i][j]의 합
		for (int i = 1; i < col; i++) mat[0][i] += mat[0][i - 1];
		for (int i = 1; i < row; i++) {
			mat[i][0] += mat[i - 1][0];
			for (int j = 1; j < col; j++)
				mat[i][j] += (mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1]);
		}

		vector<vector<int>> result;	// 결과 매트릭스

		for (int i = 0; i < row; i++) {
			// 더하는 row 범위
			int r_start = max(i - k, 0);
			int r_end = min(i + k, row - 1);
			vector<int> v;

			for (int j = 0; j < col; j++) {
				// 더하는 col 범위
				int c_start = max(j - k, 0);
				int c_end = min(j + k, col - 1);

				// [0][0]에서 시작일 때
				if (r_start == 0 && c_start == 0)
					v.push_back(mat[r_end][c_end]);
				// [i][0] or [0][j]에서 시작일 때
				else if (r_start == 0 || c_start == 0) {
					if (r_start == 0)
						v.push_back(mat[r_end][c_end] - mat[r_end][c_start - 1]);
					else
						v.push_back(mat[r_end][c_end] - mat[r_start - 1][c_end]);
				}
				// [i][j]에서 시작일 때
				else {
					int tmp = mat[r_end][c_end];

					// 윗, 왼쪽 뺌
					tmp -= mat[r_end][c_start - 1];
					tmp -= mat[r_start - 1][c_end];

					// 두 번 빠진 겹친 부분 다시 더해줌
					tmp += mat[r_start - 1][c_start - 1];

					v.push_back(tmp);
				}
			}
			result.push_back(v);
		}

		return result;
	}
};
