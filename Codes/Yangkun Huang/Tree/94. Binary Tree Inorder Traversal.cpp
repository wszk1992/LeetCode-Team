      // morris traversal
      vector<int> inorderTraversal(TreeNode* root) {     
          vector<int> result;                      
          TreeNode *cur = root, *prev = nullptr;
          while (cur != nullptr) {
              if (cur->left == nullptr) 
              {
                  result.push_back(cur->val);   // 输出parent的做孩子（inorder前继节点）
                  cur = cur->right;             // 输出parent（后继）
              }
              else 
              {
                  prev = cur->left;
                  while (prev->right != nullptr && prev->right != cur)
                  prev = prev->right;
                  if (prev->right == nullptr) { 
                      prev->right = cur;        // parent节点作为右孩子
                      cur = cur->left;
                  } 
                  else {
                      result.push_back(cur->val);  // 输出parent
                      prev->right = nullptr;       // 恢复结构
                      cur = cur->right;            // 输出parent的右孩子
                  }
              }
          }
          return result;
          }