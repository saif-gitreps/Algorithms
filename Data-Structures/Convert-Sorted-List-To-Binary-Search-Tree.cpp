class Solution {
// Naive attempt, worked tho but its naive attempt.
public:
    TreeNode* buildBSTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBSTree(nums, start, mid - 1);
        root->right = buildBSTree(nums, mid + 1, end);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> a;
        ListNode * ptr = head;
        while(ptr != NULL){
            a.push_back(ptr -> val);
            ptr = ptr -> next;
        }
        return buildBSTree(a, 0, a.size() - 1);
    }
};
