/**
attempt 1 didnt work because the logic isnt correct.
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
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode *temp,*ptr=head;
    int check;
    queue<ListNode*> q;
    if(head->val==head->next->val){
        while(head->next!=NULL && head->val==head->next->val){
            temp = head;
            check = head->val;
            head = head->next;
            delete temp;
        }
        if(head->next==NULL && head->val==check){
            head = NULL;
            return head;
        }
        else{
            temp = head;
            head = head->next;
            delete temp;
        }   
    }
    /*
    for (; ptr->next != nullptr; ptr = ptr->next) {
        if (ptr->val == ptr->next->val) {
            q.push(ptr);
            q.push(ptr->next);
            ptr=ptr->next;
        } 
        else if (!q.empty() && q.front()->val == ptr->val) {
            q.push(ptr);
        }
    }
    */
    return head;

}
};
