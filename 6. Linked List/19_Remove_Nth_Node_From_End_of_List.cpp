class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int len = 0;
        while(ptr!=NULL){
            len++;
            ptr=ptr->next;
        }
        int pos = len - n;
        ptr = head;

        if(pos==0){
            ListNode* temp = head;
            head=head->next;
            delete(temp);
            return head;
        }

        while(pos>1){
            ptr=ptr->next;
            pos--;
        }
        ListNode* temp = ptr->next;
        ptr->next =temp->next;
        delete(temp);
        return head;
    }
};

TC - O(n)
SC - O(1)
