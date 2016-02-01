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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // O(n) memory
        ListNode* p1=headA;
        ListNode* p2=headB;
        unordered_set <ListNode*> hashset;
        while(p1!=NULL||p2!=NULL)
        {
            if(hashset.find(p1)==hashset.end())
            {
                hashset.insert(p1);
            }
            else
            {
                return p1;
            }
            if(hashset.find(p2)==hashset.end())
            {
                hashset.insert(p2);
            }
            else
            {
                return p2;
            }
            if(p1!=NULL)
                p1 = p1->next;
            if(p2!=NULL)
                p2 = p2->next;
        }
        return NULL;
    }
};