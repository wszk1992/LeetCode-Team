/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int nodeNum = 0;
        ListNode* p = head;
        while(p) {
            p = p->next;
            nodeNum++;
        }
        return sortedListToBSTHelper(head, nodeNum);
    }
    
    TreeNode* sortedListToBSTHelper(ListNode* head, int nodeNum) {
        if(head == NULL || nodeNum == 0) {
            return NULL;
        }
        ListNode* mid = head;
        int midNum = nodeNum / 2;
        while(midNum--) {
            mid = mid->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBSTHelper(head, nodeNum/2);
        root->right = sortedListToBSTHelper(mid->next, nodeNum - nodeNum/2 - 1);
        return root;
    }
};