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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        bool l1_notend;
        bool l2_notend;
        ListNode* newlist=NULL;
        ListNode* Node1 = l1;
        ListNode* Node2 = l2;
        ListNode* Node3 = NULL;
        int value;
        for(;;)
        {
            if(Node1==NULL&&Node2==NULL)
                break;
            else if(Node1==NULL&&Node2!=NULL)
            {
                value = Node2->val;
                Node2=Node2->next;
            }
            else if(Node1!=NULL&&Node2==NULL)
            {
                value = Node1->val;
                Node1=Node1->next;
            }
            else if(Node1->val < Node2->val)
            {
                value = Node1->val;
                Node1=Node1->next;
            }
            else
            {
                value = Node2->val;
                Node2=Node2->next;
            }
            if(newlist == NULL)
            {
                Node3 = new ListNode(value);
                newlist = Node3;
            }
            else
            {
                Node3->next = new ListNode(value);
                Node3 = Node3->next;
            }
        }
        return newlist;
        
    }
};

//1:add fake head

//2:use recursion
