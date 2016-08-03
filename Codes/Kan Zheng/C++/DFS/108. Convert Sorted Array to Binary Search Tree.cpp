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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        int n=nums.size();
        TreeNode* root=new TreeNode(nums[n/2]);
        if(n==1)
            return root;
        else if(n==2)
        {
            TreeNode* left=new TreeNode(nums[0]);
            root->left = left;
            return root;
        }
        else
        {
            vector<int> left(nums.begin(),nums.begin()+n/2);
            vector<int> right(nums.begin()+n/2+1,nums.end());
            root->left = sortedArrayToBST(left);
            root->right = sortedArrayToBST(right);
            return root;
        }
    }
};