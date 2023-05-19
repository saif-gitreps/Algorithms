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
  // atempt 1 , i think this code got memory leak or something , but it looks so elegant.
public:
    ListNode* partition(ListNode* head, int x) {
        set<ListNode*> s;
        queue<ListNode*> orig;
        ListNode *reference,*temp,*ptr = head;
        while(ptr!=NULL){
            if(ptr->val<x){
                temp = ptr;
                s.insert(temp);
            }
            else{
                orig.push(ptr);
            }
            ptr=ptr->next;
        }
        ListNode *newHead = new ListNode(0);
        reference = newHead;
        for(auto x: s){
            newHead->next = x;
            newHead = newHead->next;
        }
        while(orig.empty()!=true){
            newHead->next = orig.front();
            newHead = newHead->next;
            orig.pop();
        }
        return reference->next;
    }
};
