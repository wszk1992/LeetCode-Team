   TreeNode* sortedArrayToBST (vector<int>& num) {
       return sortedArrayToBST(num.begin(), num.end());
   }
   template<typename RandomAccessIterator>
   TreeNode* sortedArrayToBST (RandomAccessIterator first,   RandomAccessIterator last) {
       const auto length = distance(first, last);
	   if (length <= 0) 
		   return nullptr; 
	   auto mid = first + length / 2;
	   TreeNode* root = new TreeNode (*mid);   // set mid as root of the whole tree
	   root->left = sortedArrayToBST(first, mid);  // set mid of first part of array as root of left subtree
	   root->right = sortedArrayToBST(mid + 1, last);  // mid of second part ... right subtree
	   return root;
   }