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
// so the problem weas , i needed a nums left varibale , from start till nums left
// idk why the root_index varibale logic didnt work.
public:
    TreeNode* build(vector<int> &inorder,int in_left,int in_right,vector<int> &post,int post_left,int post_right,map<int,int> &mp){
        if(in_left>in_right || post_left>post_right){
            return NULL;
        }
        TreeNode *root = new TreeNode(post[post_right]);
        int root_index = mp[root->val];
        int nums_left = root_index-in_left;
        root->left = build(inorder,in_left,root_index-1,post,post_left,post_left+nums_left-1,mp);
        root->right = build(inorder,root_index+1,in_right,post,post_left+nums_left,post_right-1,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {
        if(inorder.size()!=post.size()){
            return NULL;
        }
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return build(inorder,0,inorder.size()-1,post,0,post.size()-1,mp);
    }
};

