vector<int> preorderTraversal(TreeNode* root) { // morris traversal
          vector<int> result;
          TreeNode *cur = root, *prev = nullptr;
          while (cur != nullptr) {
              if (cur->left == nullptr) 
              {
                  result.push_back(cur->val);
                  cur = cur->right;
              }
              else 
              {
                  prev = cur->left;
                  while (prev->right != nullptr && prev->right != cur)
                  prev = prev->right;
                  if (prev->right == nullptr) { 
                      result.push_back(cur->val);   // 唯一一行不同，先输出parent
                      prev->right = cur;
                      cur = cur->left;
                  } 
                  else {
                      prev->right = nullptr;
                      cur = cur->right;
                  }
              }
          }
          return result;
          }
    