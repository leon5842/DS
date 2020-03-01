

class solution {
	private:
		int traverse(TreeNode *root, int &max_sum) {

			if (!root)
				return 0;
			int lMax = max(0, traverse(root->left, max_sum));
			int rMax = max(0, traverse(root->right, max_sum));

			max_sum = max(max_sum, lMax+rMax+root->val);

			return max(lMax, rMax) + root->val;
	public:

}
