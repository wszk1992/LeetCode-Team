   // method 1
   // go leftmost first
   // then k decrease
   int kthSmallest(TreeNode* root, int& k) {
    if (root) {
        int x = kthSmallest(root->left, k);
        return !k ? x : (!--k ? root->val : kthSmallest(root->right, k));
    }



  // method 2
  // inorder traversal
  int kthSmallest(TreeNode* root, int k) {
        int i=0,j=0;
          TreeNode *cur = root, *prev = nullptr;
          while (cur != nullptr) {
              if (cur->left == nullptr) 
              {
                  i++;
                  if(i==k)
                  j=cur->val;
                  cur = cur->right;
              }
              else 
              {
                  prev = cur->left;
                  while (prev->right != nullptr && prev->right != cur)
                  prev = prev->right;
                  if (prev->right == nullptr) { 
                      prev->right = cur;
                      cur = cur->left;
                  } 
                  else {
                      i++;
                      if(i==k)
                      j=cur->val;
                      prev->right = nullptr;
                      cur = cur->right;
                  }
              }
          }
          return j;
    }