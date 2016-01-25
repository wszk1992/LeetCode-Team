#include<iostream>
#include<vector>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 //iteration
 ListNode* reverseList(ListNode* head) {
	 if (head == NULL || head->next == NULL)
		 return head;
	 ListNode *p = head, *q = head->next, *temp = NULL;
	 for (; q != NULL; p = q, q = temp)
	 {
		 temp = q->next;
		 q->next = p;
	 }
	 head->next = NULL;
	 return p;
 }

 // recursion
 ListNode* reverseList(ListNode* head) {
	 if (head == NULL || head->next == NULL)
		 return head;
	 ListNode* newhead = head;
	 while (newhead->next != NULL)
		 newhead = newhead->next;
	 reverse(head);
	 return newhead;
 }
 ListNode* reverse(ListNode* head)
 {
	 if (head->next == NULL)
		 return head;
	 else
	 {
		 (reverse(head->next))->next = head;
		 head->next = NULL;
		 return head;
	 }
 }

 