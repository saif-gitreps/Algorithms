// passed 78/135 cases.
class Solution {
public:
    int kev(TreeNode * root, int ts, int sum){
        if(root == NULL){
            return 0;
        }
        if(sum + root->val == ts){
            return 1;
        }
        int leftpick = 0;int leftnot = 0;
        int rightpick = 0; int rightnot = 0;
        leftpick = kev(root->left, ts, sum + root->val);
        leftnot = kev(root->left, ts, sum);
        rightpick = kev(root->right, ts, sum + root->val);
        rightnot = kev(root->right, ts, sum);
        return leftpick+leftnot+rightpick+rightnot;
    }
    int pathSum(TreeNode* root, int targetSum) {
        return kev(root, targetSum, 0);
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
    int ans = 0;
    void kev(TreeNode * root, int ts, long long sum){
        if(root == NULL){
            return;
        }
        if(sum + root->val == ts){
            ans++;
        }
        kev(root->left, ts, sum + root->val);
        kev(root->right, ts, sum + root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root != NULL){
            kev(root, targetSum, 0);
            pathSum(root->left,targetSum);
            pathSum(root->right,targetSum);
        }
        return ans;
    }
};
