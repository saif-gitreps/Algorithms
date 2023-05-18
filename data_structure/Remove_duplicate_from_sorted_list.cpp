ListNode* deleteDuplicates(ListNode* head) {
  // attempt 1, why didnt it work? i think its becasue i was trying to access a pointer that was outside of range,
  // mayb the lis was of [1] her ptr->next->next does not exist .
        ListNode *temp,*ptr=head;
        if(head->val==head->next->val){
            temp = head;
            head = head->next;
        }
        for(ptr=head;ptr!=NULL;ptr=ptr->next){
            if(ptr->val==ptr->next->val && ptr->next->next!=NULL){
                temp = ptr->next;
                ptr->next= temp->next;
                delete temp;
            }
            else if(ptr->val==ptr->next->val && (ptr->next->next==NULL)){
                temp = ptr->next;
                ptr->next = NULL;
                delete temp;
            }
        }
        return head;
    }






