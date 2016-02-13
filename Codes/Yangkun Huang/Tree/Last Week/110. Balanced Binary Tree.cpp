 bool isBalanced (TreeNode* root) {  // ֱ��return height 
    return balancedHeight (root) >= 0;      // ���return�����Ƿ�ƽ��?
    }
    int balancedHeight (TreeNode* root) {    // postorder
        if (root == nullptr) // NULL= nullptr
        return 0; 
        int left = balancedHeight (root->left);
        int right = balancedHeight (root->right);
        if (left < 0 || right < 0 || abs(left - right) > 1)
        return -1; 
        return max(left, right) + 1; 
}