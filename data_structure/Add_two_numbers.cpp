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
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};
