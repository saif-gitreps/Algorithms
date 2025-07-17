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
    int getDecimalValue(ListNode* head) {
        vector<int> temp;
        while (head != NULL) {
            temp.push_back(head->val);
            head = head->next;
        }

        int n = temp.size();
        int j = 0, ans = 0;
        for (int i = n-1; i >= 0; i--) {
            ans += (temp[i] * (pow(2, j++)));
        }

        return ans;
    }
};
