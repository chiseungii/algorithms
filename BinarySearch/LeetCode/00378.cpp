class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		/*
		 [0][0] 원소 ~ [n-1][n-1] 원소
		 mid보다 작거나 같은 수의 개수와 k 비교
		*/

		int low = matrix[0][0];
		int high = matrix[matrix.size() - 1][matrix.size() - 1];
		int mid;

		while (low <= high) {
			mid = (low + high) / 2;

			int cnt = 0;
			for (int i = 0; i < matrix.size(); i++) {
				for (int j = 0; j < matrix.size(); j++) {
					if (matrix[i][j] <= mid) cnt++;
					else break;
				}
			}

			if (cnt >= k) high = mid - 1;
			else low = mid + 1;
		}

		return low;
	}
};
