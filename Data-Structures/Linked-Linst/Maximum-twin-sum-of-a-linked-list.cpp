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


=====================================================

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
// slightly better in terms of memory.
public:
    int pairSum(ListNode* head) {
        stack<int> s;
        int mx = -1;
        ListNode *ptr = head;
        while(ptr != NULL){
            s.push(ptr->val);
            ptr = ptr->next;
        }
        int n = s.size();
        ptr = head;
        for(int i = 1 ; i <= n/2; i ++){
            mx = max(mx, (ptr->val + s.top()));
            s.pop();
            ptr = ptr->next;
        }
        return mx;
    }
};


====================================================================
This is best in terms of space complexity . 
Here he reverses the array and stops the loop half way during comparision
    
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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        ListNode* fast = head, *slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        // Now slow points to the start of the second half , we need to reverse that half
        ListNode* prev = nullptr , *curr = slow, *nextCurr = slow->next;
        while(true){
            curr->next = prev;
            prev = curr;
            if(nextCurr == nullptr)
                break;
            curr = nextCurr;
            nextCurr = curr->next;
        }
        int ans = 0;
        ListNode* forward = head, *backward = curr;
        while(forward->next != backward){
            ans = max(ans,forward->val + backward->val);
            forward = forward->next;
            backward = backward->next;
        }
        return max(ans,forward->val + backward->val);
    }
};
    
    
