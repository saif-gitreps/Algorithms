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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  // modified solution , so here the deletiong conintues as long as we have a two matching pairs.
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp,*ptr=head;
        while(ptr!=NULL && ptr->next!=NULL){
            if(ptr->val==ptr->next->val){
                temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
            }
            else{
                ptr = ptr->next;
            }
        }
        return head;
    }
};





