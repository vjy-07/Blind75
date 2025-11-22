class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return NULL;
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* ptr = dummyHead;
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val < ptr2->val){
                ptr->next = ptr1;
                ptr = ptr1;
                ptr1=ptr1->next;
            }
            else{
                ptr->next =ptr2;
                ptr=ptr2;
                ptr2=ptr2->next;
            }
        }
        if(ptr1){
            ptr->next =ptr1;
        }
        if(ptr2){
            ptr->next = ptr2;
        }
        return dummyHead->next;
    }
};

TC - O(n+m)
SC - O(1)