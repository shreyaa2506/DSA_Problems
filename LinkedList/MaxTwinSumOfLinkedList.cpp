class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next !=NULL && fast->next->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode*prev = NULL;
        while(slow!=NULL){
            ListNode*nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        int maxval = 0;
        while(prev->next!=NULL){
            maxval = max(maxval,(prev->val + head->val));
            prev = prev->next;
            head=head->next;
        }
        return maxval;
    }
};