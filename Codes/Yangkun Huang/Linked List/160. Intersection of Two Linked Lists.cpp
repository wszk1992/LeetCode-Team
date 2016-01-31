ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int num1 = 1, num2 = 1;
	ListNode *p1 = headA, *p2 = headB;
	if (headA == NULL || headB == NULL)
		return NULL;
	for (; p1->next != NULL; p1 = p1->next)//������������ĳ���
		num1++;
	for (; p2->next != NULL; p2 = p2->next)
		num2++;
	if (p1 != p2)                      //β�ڵ㲻ֱͬ�ӷ���
		return NULL;
	for (int i = 0; i<abs(num1 - num2); i++)
		if (num1>num2)
			headA = headA->next;
		else
			headB = headB->next;
	for (; headA&&headB; headA = headA->next, headB = headB->next)
		if (headA == headB)
			return headA;
}