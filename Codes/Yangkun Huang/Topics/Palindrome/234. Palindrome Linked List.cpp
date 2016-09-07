#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *p;
bool isPalindrome(ListNode* head) {
	ListNode *lst;
	if (head == NULL || head->next == NULL)
		return true;
	p = head;
	return judge(head);
}
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