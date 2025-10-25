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
// my soln, not so efficient.
public:
    void dfs(TreeNode *root, vector<int> &a) {
        if (root == NULL) {
            a.push_back(-5000);
            return;
        }

        a.push_back(root->val);
        dfs(root->left, a);
        dfs(root->right, a);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> tree1;
        vector<int> tree2;
        dfs(p, tree1);
        dfs(q, tree2);

        int i = 0, j = 0;
        while(i < tree1.size() && j < tree2.size()) {
            if (tree1[i] != tree2[j]) {
                return false;
            }
            i++;
            j++;
        }

        if (i < tree1.size() || j < tree2.size()) {
            return false;
        }

        return true;
    }
};


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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }
};
