/**
// my solution , worked, breat 78%
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *temp,*ptr;
        int limit = 0;
        for(ptr = head ; ptr != NULL; ptr=ptr->next){
            limit++;
        }
        if(limit==1){
            head = NULL;
            return head;
        }
        ptr = head;
        limit = limit/2;
        for(int i=0;i<limit-1;i++){
            ptr=ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        return head;
    }
};
