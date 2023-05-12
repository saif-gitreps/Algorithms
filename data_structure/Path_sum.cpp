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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        if(root->val==targetSum && root->left==NULL && root->right==NULL){
            return true;
        }
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
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
class Solution2{
    // need to study this alg
public:
    bool pathSum(TreeNode *root, int targetSum, int sum) {
        if(root==NULL)
            return false;
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL && sum==targetSum)
            return true;
        return pathSum(root->left, targetSum, sum) || pathSum(root->right, targetSum, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return pathSum(root, targetSum, sum);
    }
};
