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
// easyyyyyy
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0, current_k = k;
        vector<ListNode*> ans;
        ListNode *ptr = head;
        
        while (ptr) {
            len++;
            ptr = ptr -> next;
        }

        ptr = head;
        
        for (int i = 1; i <= k; i++) {
            int group_size = ceil(double((double)len / current_k));
            len -= group_size;
            current_k--;

            ListNode *temp = new ListNode(0),*temp_ptr;
            temp_ptr = temp;
            while (group_size && ptr  != NULL) {
                temp -> next = ptr;
                ptr = ptr -> next;
                temp = temp -> next;
                group_size--;
            }
            temp -> next = NULL;
            ans.push_back(temp_ptr -> next);
        } 

        return ans;
    }
};
