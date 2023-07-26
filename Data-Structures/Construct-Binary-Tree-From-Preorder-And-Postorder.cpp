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
    TreeNode* build(vector<int> &pre,int pre_left,int pre_right,vector<int> &in,int in_left,int in_right,map<int,int> mp){
        if(pre_left>pre_right || in_left>in_right){
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[pre_left]);
        int root_index = mp[root->val];
        int nums_right = pre_right - root_index;
        int nums_left = root_index - in_left;
        root->left = build(pre,pre_left+1,nums_left,in,in_left,root_index-1,mp);
        root->right = build(pre,pre_left+nums_left+1,pre_right,in,root_index+1,in_right,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if(pre.size()!=in.size()){
            return NULL;
        }
        map<int,int> mp;
        for(int i=0;i<in.size();i++){
            mp[in[i]] = i;
        }
        return build(pre,0,pre.size()-1,in,0,in.size()-1,mp);
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
//first solution has some issues, second solution works well.
public:
    TreeNode* build(vector<int> &pre,int pre_left,int pre_right,vector<int> &in,int in_left,int in_right,map<int,int> &mp){
        if(pre_left>pre_right || in_left>in_right){
            return NULL;
        }
        TreeNode *root = new TreeNode(pre[pre_left]);
        int root_index = mp[root->val];
        int nums_left = root_index - in_left;
        root->left = build(pre,pre_left+1,pre_left+nums_left,in,in_left,root_index-1,mp);
        root->right = build(pre,pre_left+nums_left+1,pre_right,in,root_index+1,in_right,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if(pre.size()!=in.size()){
            return NULL;
        }
        map<int,int> mp;
        for(int i=0;i<in.size();i++){
            mp[in[i]] = i;
        }
        return build(pre,0,pre.size()-1,in,0,in.size()-1,mp);
    }
};
