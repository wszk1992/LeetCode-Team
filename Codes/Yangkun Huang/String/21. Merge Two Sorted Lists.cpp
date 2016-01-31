#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode head(0);
	ListNode *temp = NULL, *temp2 = NULL, *q = NULL, *p = &head;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val < l2->val)
	{
		head.next = l1;
		q = l2;
	}
	else
	{
		head.next = l2;
		q = l1;
	}
	for (; p->next != NULL && q != NULL; p = p->next)
		if (p->next->val >= q->val)
		{
			temp = p->next;
			p->next = q;
			temp2 = q->next;
			q->next = temp;
			q = temp2;
		}
	if (q != NULL)
		p->next = q;
	return head.next;
}

// 添加头结点简化算法