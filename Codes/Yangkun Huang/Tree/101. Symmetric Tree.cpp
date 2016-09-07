    // recursive
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
         return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)          // both are NULL, return true
            return true;                               
        if (p == nullptr || q == nullptr)          // either is not NULL, return false
            return false;                              // if neither are NULL, compare both values and continue
        return p->val == q->val&& isSymmetric(p->left, q->right)&& isSymmetric(p->right, q->left);  
    }                                                                                            
    
    // iterative
    bool isSymmetric (TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while (!s.empty ()) {
            auto p = s.top (); s.pop();
            auto q = s.top (); s.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
