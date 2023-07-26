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
    ListNode* middleNode(ListNode* head) {
        int n =1 ;
        ListNode *ptr=head;
        while(ptr!=NULL){
            n++;
            ptr=ptr->next;
        }
        int mid = floor(n/2);
        if(n%2!=0){
            mid++;
        }
        ptr =head;
        for(int i=1;i<mid;i++){
            ptr = ptr->next;
        }
        return ptr;
        
    }
};
