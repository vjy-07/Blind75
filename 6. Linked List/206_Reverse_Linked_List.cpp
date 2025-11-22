class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* ptr = head;
        ListNode* pre = NULL;
        while(ptr!=NULL){
            ListNode* nex = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = nex;
        }
        return pre;
    }
};

TC - O(n)
SC - O(1)
