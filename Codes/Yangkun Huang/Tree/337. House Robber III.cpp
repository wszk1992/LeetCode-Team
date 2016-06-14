    int rob(TreeNode* root) {
    vector<int> res = robSub(root);
    return max(res[0], res[1]);
}
	
	// the first element of which denotes the maximum amount of money that can be robbed if "root" is not robbed
	// the second element signifies the maximum amount of money robbed if root is robbed

    vector<int> robSub(TreeNode* root) {
    if (root == NULL) {
        return vector<int>(2,0);
    }

    vector<int> left = robSub(root->left);          // store intermediate value in vectors
	vector<int> right = robSub(root->right);        // otherwise it would calculate in each step of recursion

    vector<int> res(2,0);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);  // if only one child was robbed, root cannot be robbed
    res[1] = root->val + left[0] + right[0];                   // while the other child still needs to check if robbed would have higher amount
    return res;
}