#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
	ListNode *p1 = head, *p2, *tag;
	if (head == NULL || head->next == NULL)
		return head;
	else
	{
		tag = head->next;
		p2 = head->next;
	}
	for (; p1->next != NULL&&p2->next != NULL; p1 = p1->next, p2 = p2->next)
	{
		p1->next = p1->next->next;
		p2->next = p2->next->next;
	}
	p1->next = tag;
	return head;
	}

// ÷∏’Î≥ı ºªØ

int main()
{
	ListNode a(1);
	ListNode *p = &a;
	p=oddEvenList(p);
	cout << p->val << endl;
	system("pause");
}