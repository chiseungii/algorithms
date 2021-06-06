class Solution {
private:
	vector<int> nums;	// 정수를 순서대로 넣을 벡터

public:
	void inorder(TreeNode* node) {
		if (node == NULL) return;

		inorder(node->left);
		nums.push_back(node->val);
		inorder(node->right);
	}

	int kthSmallest(TreeNode* root, int k) {
		// inorder 사용해 벡터에 저장
		inorder(root);

		// k번째 리턴
		return nums[k - 1];
	}
};
