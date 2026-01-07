/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
// needed a lil bit of hint, key idea is that all we gotta to is know the sum of a sub tree 
// then we can subtract sum_entire tree - selected sub tree to get the other half of the tree. 
public:
    map<TreeNode*, int> mp;
    
    int sum_dfs(TreeNode *root) {
        if (root == NULL) return 0;

        if (mp.find(root) != mp.end()) return mp[root];
        
        return mp[root] = root->val + sum_dfs(root->left) + sum_dfs(root->right);
    }

    int maxProduct(TreeNode* root) {
        sum_dfs(root);
        const int mod = 1e9 + 7;
        long long mx = 0;
        int sum_tree = mp[root];
        for (auto it: mp) {
            mx = max(mx,(long long)(sum_tree - it.second) * it.second) ;
        }    
        return mx % mod;
    }
};

// this here first call calcs the total, second fr finding res, does 2 func job with 1 func code
    long res = 0, total = 0, sub;
    int maxProduct(TreeNode* root) {
        total = s(root), s(root);
        return res % (int)(1e9 + 7);
    }

    int s(TreeNode* root) {
        if (!root) return 0;
        sub = root->val + s(root->left) + s(root->right);
        res = max(res, sub * (total - sub));
        return sub;
    }
