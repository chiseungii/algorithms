class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		int col = matrix[0].size();

		/*
		 target이 아예 없는 행 제외
		*/

		// 제일 끝 원소가 5보다 작으면 제외
		int low = 0;
		while (low < row && matrix[low][col - 1] < target) low++;

		// 제일 앞 원소가 5보다 크면 제외
		int high = row - 1;
		while (high >= 0 && matrix[high][0] > target) high--;

		/*
		 각 행마다 binary search 이용해서 target 찾기
		*/

		for (int i = low; i <= high; i++) {
			int left = 0, right = col - 1, mid;

			while (left <= right) {
				mid = (left + right) / 2;

				if (matrix[i][mid] == target) return true;
				else if (target > matrix[i][mid]) left = mid + 1;
				else right = mid - 1;
			}
		}

		return false;
	}
};
