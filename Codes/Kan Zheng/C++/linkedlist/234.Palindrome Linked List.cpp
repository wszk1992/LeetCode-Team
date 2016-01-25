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
    bool isPalindrome(ListNode* head) {
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
        ListNode* Node1=head;
        ListNode* Node2=verseNode;
        for(;Node1!=NULL||Node2!=NULL;Node1=Node1->next,Node2=Node2->next)
        {
            if(Node1->val!=Node2->val)
                return false;
        }
        return true;
    }
};

//advanced method
p = head;
bool judge(ListNode *head)
{
	if (head == NULL)
		return true;
	if (judge(head->next) == false)
		return false;
	if (p->val != head->val)
		return false;
	else
	{
		p = p->next;
		return true;
	}
}
