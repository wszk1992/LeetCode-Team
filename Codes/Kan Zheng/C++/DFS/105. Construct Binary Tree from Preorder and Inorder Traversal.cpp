/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return buildTreeHelper(preorder, inorder, 0, inorder.size(), preIndex);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int start, int end, int& preIndex) {
        TreeNode* root;
        int pos;
        if(preIndex >= preorder.size()) {
            return NULL;
        }
        else if((pos = findIndex(inorder, preorder[preIndex], start, end)) == -1) {
            preIndex--;
            return NULL;
        }else {
            root = new TreeNode(preorder[preIndex]);
        }
        root->left = buildTreeHelper(preorder, inorder, start, pos, ++preIndex);
        root->right = buildTreeHelper(preorder, inorder, pos+1, end, ++preIndex);
        return root;
    }
    
    int findIndex(vector<int> vec, int target, int start, int end) {
        for(int i = start; i < end; i++) {
            if(vec[i] == target) {
                return i;
            }
        }
        return -1;
    }
};