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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* sudohead = new ListNode(-1);
        sudohead->next = head;
        ListNode* p_sec=sudohead;
        ListNode* p=head;
        ListNode* temp;
        while(p->next!=NULL)
        {
            while(p!=p_sec)
            {
                if((p->next->val<=p_sec->next->val))
                {
                    temp=p->next;
                    p->next = temp->next;
                    temp->next = p_sec->next;
                    p_sec->next=temp;
                    break;
                }
                else
                    p_sec=p_sec->next;
            }
            if(p==p_sec)
                p=p->next;
            p_sec = sudohead;
        }
        return sudohead->next;
    }
};