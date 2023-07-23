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
//attemp1: idk why i am getting overflow , it seems fine to me.
public:
    TreeNode* making_tree(int left,int right,vector<int> inorder,vector<int> post){
        TreeNode *root = new TreeNode(post[right]);
        if(left>=right){
            root->right=NULL;
            root->left=NULL;
            return root;
        }
        int root_index;
        TreeNode *left_tree;
        TreeNode *right_tree;
        for(int i=left;i<=right;i++){
            if(inorder[i]==root->val){
                root_index = i; break;
            }
        }
        left_tree = making_tree(left,root_index-1,inorder,post);
        right_tree = making_tree(root_index+1,right,inorder,post);
        root->left = left_tree;
        root->right = right_tree;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {
        TreeNode *root;
        root = making_tree(0,inorder.size()-1,inorder,post);
        return root;
    }
};
