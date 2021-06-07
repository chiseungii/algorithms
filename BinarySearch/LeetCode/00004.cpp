class Solution {
private:
	int findIndex(vector<int> v, int n) {
		if (v.empty()) return 0;
		if (n <= v[0]) return 0;
		if (n > v[v.size() - 1]) return v.size();

		int low = 0, high = v.size() - 1, mid;

		while (low < high) {
			mid = (low + high) / 2;

			if (n <= v[mid]) high = mid;
			else low = mid + 1;
		}

		return low;
	}

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		/*
		 binary search를 이용해 nums2의 정수를 nums1에 추가
		*/

		for (int n : nums2) {
			int index = findIndex(nums1, n);
			nums1.insert(nums1.begin() + index, n);
		}

		// 원소가 홀수개면 가운데 수 리턴
		if (nums1.size() % 2)
			return nums1[nums1.size() / 2];
		// 짝수개면 중간 둘의 평균값 리턴
		else {
			int tmp = (nums1.size() - 1) / 2;
			return ((double)nums1[tmp] + (double)nums1[tmp + 1]) / 2.;
		}
	}
};
