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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {        
        ListNode *prev = head,*curr = head;
        if(prev->next == NULL){
            return head;
        }
        curr = curr->next;
        while(curr != NULL){
            ListNode *newNode = new ListNode(__gcd(prev->val,curr->val));
            prev->next = newNode;
            newNode->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
