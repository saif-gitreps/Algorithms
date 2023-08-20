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
// first attempt , my ideas are not connecting.
public:
    //map<> visited(1000,false);
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root==NULL){
            return ans;
        }
        ans.push_back({root->val});
        queue<*TreeNode> q;
        q.push(root);
        while(q.empty()==false){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            else if(temp->right!=NULL){
                q.push(temp->right);
            }
        }

    }
};
