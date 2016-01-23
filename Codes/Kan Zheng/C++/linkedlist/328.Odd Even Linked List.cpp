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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* l1=head;
        ListNode* l2=head->next;
        ListNode* Node1=l1;
        ListNode* Node2=l2;
        bool flag=1;
        for(;;)
        {
            if(Node1->next!=NULL&&Node2->next!=NULL)
            { 
                if(flag)
                {
                    Node1->next = Node2->next;
                    Node1 = Node1->next;
                }
                else
                {
                    Node2->next = Node1->next;
                    Node2 = Node2->next;
                }
                flag = 1- flag;
            }
            else
            {
                Node1->next = l2;
                Node2->next = NULL;
                break;
            }
        }
        return l1;
    }
};