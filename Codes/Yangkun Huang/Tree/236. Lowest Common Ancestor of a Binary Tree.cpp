TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)              // µÝ¹é·µ»ØÌõ¼þ
        return root;
        TreeNode *ltree = lowestCommonAncestor(root->left,p,q);  // find p or q in left subtree
        TreeNode *rtree = lowestCommonAncestor(root->right,p,q); // find p or q in right subtree
        if(ltree && rtree)                                       // if found, return
        return root;
        return rtree?rtree:ltree;                                // if not found, return that ptr which is NULL
    }