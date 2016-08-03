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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, 0, inorder.size(), postIndex);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int start, int end, int& postIndex) {
        TreeNode* root;
        int pos;
        if(postIndex < 0) {
            return NULL;
        }
        else if((pos = findIndex(inorder, postorder[postIndex], start, end)) == -1) {
            postIndex++;
            return NULL;
        }else {
            root = new TreeNode(postorder[postIndex]);
        }
        root->right = postIndex >= 0 ? buildTreeHelper(inorder, postorder, pos+1, end, --postIndex) : NULL;
        root->left = postIndex >= 0 ? buildTreeHelper(inorder, postorder, start, pos, --postIndex) : NULL;
        return root;
    }
    
    int findIndex(vector<int>& vec, int target, int start, int end) {
        for(int i = start; i < end; i++) {
            if(vec[i] == target) {
                return i;
            }
        }
        return -1;
    }
};