ListNode *sortList(ListNode *head) {
    if(!head)
        return NULL;
    if(!head->next)
        return head;
    ListNode *p1 = head;
    ListNode *p2 = head->next;
    while(p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    ListNode *headb = p1->next;
    p1->next = NULL;
    return merge(sortList(head), sortList(headb));
}

ListNode *merge(ListNode *p1, ListNode *p2) {
    ListNode *head = new ListNode(-1);
    ListNode *index = head;
    while(p1 && p2) {
        if(p1->val <= p2->val) {
            index->next = p1;
            p1 = p1->next;
            index = index->next;
        }
        else {
            index->next = p2;
            p2 = p2->next;
            index = index->next;
        }
    }
    while(p1) {
        index->next = p1;
        p1 = p1->next;
        index = index->next;
    }
    while(p2) {
        index->next = p2;
        p2 = p2->next;
        index = index->next;
    }
    index->next = NULL;
    return head->next;
}
