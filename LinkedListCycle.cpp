bool hasCycle(ListNode *head) {
    if(!head || !head->next)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast->next && fast->next->next) {
        if(slow == fast) {
            return true;
        }
        else {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return false;
}
