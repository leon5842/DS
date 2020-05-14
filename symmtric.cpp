class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			queue<TreeNode*> q;
			int levels = 0;

			q.push(root);
			q.push(root);
			if (!root)
				return true;

			while (!q.empty()) {
				TreeNode *cur1 = q.front(); q.pop();
				TreeNode *cur2 = q.front(); q.pop();
				if (!cur1 && !cur2)
					continue;
				if (cur1 == NULL || cur2  == NULL)
					return false;
				if (cur1->val != cur2->val) return false;
				q.push(cur1->left);
				q.push(cur2->right);
				q.push(cur1->right);
				q.push(cur2->left);

			}
			return true;
		}
};

bool isSymmetric(TreeNode* root) {
	if(!root) return true;
	return helper(root->left, root->right);
}
bool helper(TreeNode* left, TreeNode* right){
	if(!left && !right) return true;
	if(!left || !right) return false;
	return (left->val == right->val) && helper(left->left, right->right) && helper(left->right, right->left);
}
