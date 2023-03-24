ListNode* removeNthFromEnd(ListNode* head, int n) {

        
        ListNode*temp = head;
        int c = 0;
        while(temp!=NULL){
            c=c+1;
            temp = temp->next;
        }
        if(c==0){
            return NULL;
        }
        if(c==n){
            return head->next;
        }
        int num = c-n;
        temp = head;
        int i =0;
        while(temp){
            i++;
            if(i==num){
                temp->next = temp->next->next;
            }
            temp = temp->next;
            
        }
  return head;
    }
