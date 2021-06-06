class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		/*
		 A + B + C + D = 0
		 -> (A + B) = -(C + D) 이용
		*/
		map<int, int> nums;	// nums1과 nums2을 더해서 나온 결과 <결과, 개수>

		for (int num1 : nums1)
			for (int num2 : nums2)
				nums[num1 + num2]++;

		// num3과 nums4를 더해서 나온 결과 카운트
		int cnt = 0;

		for (int num3 : nums3)
			for (int num4 : nums4)
				cnt += nums[-(num3 + num4)];

		return cnt;
	}
};
