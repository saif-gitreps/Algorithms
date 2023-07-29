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
// my attempt. i mean i am happy it worked, its O(p+q+s+t) in time and space O(s1+s2+ans) so yea not a memory efficient code
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<ListNode*> s1,s2;
        stack<ListNode*> ans;
        ListNode *ptr1 = l1,*ptr2 = l2;
        int carry = 0;
        while(ptr1!=NULL){
            s1.push(ptr1);
            ptr1 = ptr1->next;
        }
        while(ptr2!=NULL){
            s2.push(ptr2);
            ptr2 = ptr2->next;
        }
        while(!s1.empty() || !s2.empty() || carry){
            int num1,num2,res;
            num1 = (!s1.empty())?s1.front()->val:0;
            num2 = (!s2.empty())?s2.front()->val:0;
            
            if(s1.empty()!=true){s1.pop();}
            if(s2.empty()!=true){s2.pop();}
            
            
            res = num1+num2+carry;
            
            ListNode *temp = new ListNode();
            
            if(res<=9){
                temp->val = res;
                ans.push(temp);
                carry = 0;
            }
            else if(res>9){
                temp->val = res%10;
                ans.push(temp);
                carry = res/10;
            }
        }
        ListNode *head,*ptr;
        head = ans.top(); ans.pop();
        ptr = head;
        ptr->next = NULL;
        while(!ans.empty()){
            ListNode *tmp = new ListNode(); 
            tmp = ans.top(); ans.pop();
            tmp->next = ptr;
            ptr = tmp;
        }
        return ptr;
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
// i am so stupid, i could have avoided using queue altogether , i just dont think straight
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
