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
attempt 1 : idk why i cant debug whats wrong here.
public:
    vector<string> ans;
    void pre(TreeNode *root,string &ds){
        if(root == NULL){
            ans.push_back(ds);
            return;
        }
        ds.push_back(root->val + '0');
        pre(root->left,ds);
        ds.pop_back();
        pre(root->right,ds);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string ds = "";
        pre(root,ds);
        for(int i= 0 ; i < ans.size(); i ++){
            int num = 0;
            for(int j = 0 ; j < ans[i].size(); j++){
                num = (num * 10) + (ans[i][j] - '0');
            }
            sum += num;
        }
        return sum;

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
// same result but this is much much better in terms of space from O(n^2) to O(1).
public:
    int ans = 0;
    void pre(TreeNode *root,int &ds){
        if(root == NULL){
            ans += ds;
            return;
        }
        ds = ds*10 + (root->val);
        pre(root->left,ds);
        if(ds!=0){
            ds = ds/10;
        }
        else{
            ds = 0;
        }
        pre(root->right,ds);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int ds = 0;
        pre(root,ds);
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
// working solution.
public:
    int ans = 0;
    void pre(TreeNode *root,int ds){
        if(root == NULL){
            return;
        }
        ds = ds*10;
        ds += (root->val);

        if(root->left == NULL && root->right == NULL){
            ans += ds;
            return;
        }
        pre(root->left,ds);
        pre(root->right,ds);
    }
    int sumNumbers(TreeNode* root) {
        int ds = 0;
        pre(root,ds);
        return ans;

    }
};
