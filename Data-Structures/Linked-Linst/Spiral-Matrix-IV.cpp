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
// key part i was missing, i didn't set right and bottom one index less.
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int left_wall = 0, right_wall = n - 1;
        int top_wall = 0, bottom_wall = m - 1;
        
        while (head != NULL && left_wall <= right_wall && top_wall <= bottom_wall) {
            // Move from left to right along the top wall.
            for (int i = left_wall; i <= right_wall && head != NULL; i++) {
                ans[top_wall][i] = head->val;
                head = head->next;
            }
            top_wall++;
            
            // Move from top to bottom along the right wall.
            for (int i = top_wall; i <= bottom_wall && head != NULL; i++) {
                ans[i][right_wall] = head->val;
                head = head->next;
            }
            right_wall--;
            
            // Move from right to left along the bottom wall.
            for (int i = right_wall; i >= left_wall && head != NULL; i--) {
                ans[bottom_wall][i] = head->val;
                head = head->next;
            }
            bottom_wall--;
            
            // Move from bottom to top along the left wall.
            for (int i = bottom_wall; i >= top_wall && head != NULL; i--) {
                ans[i][left_wall] = head->val;
                head = head->next;
            }
            left_wall++;
        }
        
        return ans;
    }
};
