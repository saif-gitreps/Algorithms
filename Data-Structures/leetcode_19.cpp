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

class Solution2 {
    //unique soln
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {  
        vector<ListNode*> v;
        
        v.reserve(30);

        while(head)
        {
            v.push_back(head);

            head = head->next;
        }

        int size = v.size();

        if(size == n)
        {
            return v[0]->next;
        }
        else
        {
            head = v[size - n - 1];

            head->next = v[size - n]->next;
        }
        return v[0];
    }
};

class Solution4 {
public:
    //typical soln
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*slow=head;
        for(int i=1;i<=n;i++){
            fast = fast->next;
        }
        if(fast==NULL){
            return head->next;
            // this line means if there is such traversal wherere we reached the end of the list and the ptr is now null
        }
        while(fast->next!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return head;
    }
};
