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
    //iteration   leftrootsum=rootsum * 10 + left; rightrootsum = rootsum * 10 + right
    int sumNumbers(TreeNode* root){
        if(!root) {
            return 0;
        }
        vector<TreeNode*> nodeList_old(1, root);
        vector<TreeNode*> nodeList_new;
        vector<int> sumList_old(1, root->val);
        vector<int> sumList_new;
        int sum = 0;
        
        while(!nodeList_old.empty()) {
            for(int i = 0; i < nodeList_old.size(); i++) {
                if(nodeList_old[i]->left) {
                    nodeList_new.push_back(nodeList_old[i]->left);
                    sumList_new.push_back(sumList_old[i] * 10 + nodeList_old[i]->left->val);
                }
                if(nodeList_old[i]->right) {
                    nodeList_new.push_back(nodeList_old[i]->right);
                    sumList_new.push_back(sumList_old[i] * 10 + nodeList_old[i]->right->val);
                }
                if(!nodeList_old[i]->left && !nodeList_old[i]->right) {
                    sum += sumList_old[i];
                }
            }
            nodeList_old = nodeList_new;
            nodeList_new.clear();
            sumList_old = sumList_new;
            sumList_new.clear();
        }
        return sum;
    }
};