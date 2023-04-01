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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp,*i;
        int limit = 0,j;
        for(i=head;i!=NULL;i = i->next){
            limit++;
        }
        limit -= n;
        i = head;
        for(j=0;j<limit-1 && i!=NULL;j++){
            i = i->next; }
        if(i==head && i->next==NULL){
            delete head;
            head = NULL;
        }
        else if(limit==0){
            temp = head;
            head = head->next;
            delete temp;
        }
        else if(i->next->next==NULL){
            temp = i->next;
            delete temp;
            i->next = NULL;
        }
        else{
            temp = i->next;
            i->next = temp->next;
            delete temp;
        }
        return head;
    }
};
