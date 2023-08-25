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
// Worked till 37 test cases , i need to work on my problem.
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
            int level;
            int n = q.size();
            TreeNode *temp = q.front(); 
            q.pop(); 
            bool take = true;
            for( int i = 0 ; i < n ; i++ ){
                if(temp-> right != NULL){
                    q.push(temp->right);
                    level = temp->right->val;
                }
                else if(temp-> right == NULL && temp-> left != NULL){
                    q.push(temp->left);
                    take = false;
                }
            }
            if(take){
                ans.push_back(level);
            }
        }
        ans.pop_back();
        return ans;
    }
};
