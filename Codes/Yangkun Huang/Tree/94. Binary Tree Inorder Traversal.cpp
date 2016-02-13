      // morris traversal
      vector<int> inorderTraversal(TreeNode* root) {     
          vector<int> result;                      
          TreeNode *cur = root, *prev = nullptr;
          while (cur != nullptr) {
              if (cur->left == nullptr) 
              {
                  result.push_back(cur->val);   // ���parent�������ӣ�inorderǰ�̽ڵ㣩
                  cur = cur->right;             // ���parent����̣�
              }
              else 
              {
                  prev = cur->left;
                  while (prev->right != nullptr && prev->right != cur)
                  prev = prev->right;
                  if (prev->right == nullptr) { 
                      prev->right = cur;        // parent�ڵ���Ϊ�Һ���
                      cur = cur->left;
                  } 
                  else {
                      result.push_back(cur->val);  // ���parent
                      prev->right = nullptr;       // �ָ��ṹ
                      cur = cur->right;            // ���parent���Һ���
                  }
              }
          }
          return result;
          }