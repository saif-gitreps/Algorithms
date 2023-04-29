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
// idk why this is not working , it should work.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode *p1=list1,*p2=list2,*head,*ptr= new ListNode();
        if(p1->val<p2->val){
            ptr = p1;
            p1 = p1->next;
        }
        else{
            ptr = p2;
            p2 = p2->next;
        }
        head = ptr;
        while(!p1 && !p2){
            if(p1->val<=p2->val){
                ptr->next = p1;
                ptr = p1;
                p1 = p1->next;
            }
            else if(p2->val<=p1->val){
                ptr->next = p2;
                ptr = p2;
                p2 = p2->next;
            }
            
        }
        if(p1==NULL){
            ptr->next = p2;
        }
        if(p2==NULL){
            ptr->next = p1;
        }
        return head;
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
class Solution2 {
    // this solution works , all i need to do now is update it.
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode *p1=list1,*p2=list2,*head,*ptr= new ListNode();
        head = ptr;
        while(p1 && p2){
            if(p1->val<p2->val){
                ptr->val = p1->val;
                p1 = p1->next;
            }
            else{
                ptr->val = p2->val;
                p2 = p2->next;
            }
            ptr->next = new ListNode();
            ptr = ptr->next;
        }
        if(p1!=NULL){
            while(p1){
                ptr->val = p1->val;
                p1 = p1->next;
                if(p1==NULL){
                    ptr->next = NULL;
                }
                else{
                    ptr->next = new ListNode();
                    ptr = ptr->next;
                }
            }
        }
        if(p2!=NULL){
            while(p2){
                ptr->val = p2->val;
                p2 = p2->next;
                if(p2==NULL){
                    ptr->next = NULL;
                }
                else{
                    ptr->next = new ListNode();
                    ptr = ptr->next;
                }
            }
        }
        return head;
    }
};
