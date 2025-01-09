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
// haha was able to solve idc, wil have to revisit other sols.
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if (!root) {
            return ans;
        }
        // ans.push_back(root->val);
        map<int, int> mp;

        queue<pair<TreeNode*,int>> q;

        q.push({root, 0});

        while(!q.empty()) {
            TreeNode *curr = q.front().first;
            int level = q.front().second;

            q.pop();

            if (mp.find(level) == mp.end()) {
                mp[level] = curr->val;
            } else {
                mp[level] = max(curr->val, mp[level]);
            }

            if (curr->left != NULL) {
                q.push({
                    curr->left,
                    level + 1
                });
            }

            if (curr->right != NULL) {
                q.push({
                    curr->right,
                    level + 1
                });
            }
        }

        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
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
// found a better and clever solution. Here we know that the answer variable cannot be fixed becauese we dont know the
// the fixed number of depth that we might have to go. that solves the problem.
public:
    void dfs(TreeNode *root, int depth, vector<int> &ans) {
        if (root == NULL) {
            return;
        }

        if ( depth >= ans.size()) {
            for (int i = ans.size(); i <= depth; i++) {
                ans.push_back(0);
            }
            ans[depth] = root->val;
        } else {
            ans[depth] = max(root->val, ans[depth]);
        }

        dfs(root->left, depth+1, ans);
        dfs(root->right, depth+1, ans);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
