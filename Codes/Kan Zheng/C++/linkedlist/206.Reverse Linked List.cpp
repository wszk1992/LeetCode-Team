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
