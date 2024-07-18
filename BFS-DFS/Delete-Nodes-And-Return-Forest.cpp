/**
 This was kinda hard but hey atleast i solved it on my own.
 */
class Solution {
public:
    bool check_delete(int val, vector<int> &to_delete) {
        int L = 0, R = to_delete.size() -1 ;
        while (L <= R) {
            int mid = (L + R) / 2;
            
            if (to_delete[mid] == val) return true;
            
            if (to_delete[mid] > val) R = mid - 1;
            
            else L = mid + 1;
        }
        return false;
    }

    bool dfs(TreeNode *root, TreeNode *parent,vector<int>& to_delete, vector<TreeNode*>& ans) {
        if (root == NULL) return false;

        dfs(root->left, root, to_delete, ans);
        dfs(root->right, root, to_delete, ans);

        if (check_delete(root->val, to_delete)) {
            if (parent && parent->left && parent->left->val == root->val) 
                parent->left = NULL;
            else if (parent && parent->right && parent->right->val == root->val)
                parent->right = NULL;
            return true;
        }

        if (parent == NULL || (parent && check_delete(parent->val, to_delete)))
            ans.push_back(root);

        return false;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        sort(to_delete.begin(), to_delete.end());
        dfs(root, NULL, to_delete, ans);
        return ans;
    }
};
