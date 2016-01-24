#include<iostream>
#include<vector>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* reverseList(ListNode* head) {
	 if (head->next == NULL)
		 return head;
	 else
	 {
		 (reverseList(head->next))->next = head; 
		 head->next = NULL;
		 return head;
	 }
 }

 