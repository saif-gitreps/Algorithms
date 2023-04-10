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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *ref;
        ref = l3;
        int rem = 0;
        while(l1!=NULL && l2!=NULL){
            int num = l1->val + l2->val + rem;
            ListNode *temp = new ListNode();
            temp->val = num%10;
            rem = num/10;
            l3->next = temp;
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int num = l1->val+ rem;
            ListNode *temp = new ListNode();
            temp->val = num%10;
            rem = num/10;
            l3->next = temp;
            l3 = l3->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int num = l2->val + rem;
            ListNode *temp = new ListNode();
            temp->val = num%10;
            rem = num/10;
            l3->next = temp;
            l3 = l3->next;
            l2 = l2->next;
        }
        if(rem>0){
            ListNode *temp = new ListNode();
            temp->val = rem;
            l3->next = temp;
            l3 = l3->next;
        }
        return ref->next;
    }
};
