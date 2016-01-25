/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* Node=NULL;
        ListNode* tempNode=NULL;
        ListNode* verseNode=NULL;
        for(Node=head;Node!=NULL;Node=Node->next)
        {
            verseNode = new ListNode(Node->val);
            if(Node!=head)
                verseNode->next = tempNode;
            tempNode = verseNode;
        }
        return verseNode;
    }
};

