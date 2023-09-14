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
    int pairSum(ListNode* head) {
        stack<ListNode*> s;
        int mx = -1;
        ListNode *ptr = head;
        while(ptr != NULL){
            s.push(ptr);
            ptr = ptr->next;
        }
        int n = s.size();
        ptr = head;
        for(int i = 1 ; i <= n/2; i ++){
            int num = s.top()->val; s.pop();
            mx = max(mx, (ptr->val + num));
            ptr = ptr->next;
        }
        return mx;
    }
};
