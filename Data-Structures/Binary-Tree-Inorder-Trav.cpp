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
   vector<int> v;
   
   void in(TreeNode* root){
      if(root==NULL){
         return;
      }
      in(root->left);
      v.push_back(root->val);
      in(root->right);
   }

    vector<int> inorderTraversal(TreeNode* root) {
       in(root);
       return v;
    }
};
