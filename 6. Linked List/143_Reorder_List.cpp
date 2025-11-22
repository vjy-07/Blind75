class Solution {
public:
    void reorderList(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast!=NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
       }
       ListNode* second = slow->next;
       slow->next = nullptr;
       ListNode* pre = NULL;

       while(second){
        ListNode* nex = second->next;
        second->next = pre;
        pre = second;
        second = nex;
       }
       ListNode* first = head;
       second = pre;

       while(second){
        ListNode* temp1= first->next;
        ListNode* temp2 = second->next;
        first->next =second;
        second->next = temp1;
        first = temp1;
        second = temp2;
       }
    }
};

TC - O(n)
SC - O(1)