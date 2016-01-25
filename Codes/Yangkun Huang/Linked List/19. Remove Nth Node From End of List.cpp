#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *p = head, *q = head;
	int num = 0;
	while (p->next != NULL)
	{
		if (num >= n)
			q = q->next;
		num++;
		p = p->next;
	}
	if (num + 1 == n)
		head = head->next;
	else
		q->next = q->next->next;
	return head;
}