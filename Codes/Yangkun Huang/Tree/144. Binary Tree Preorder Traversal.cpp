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
                      result.push_back(cur->val);   // Ψһһ�в�ͬ�������parent
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
    