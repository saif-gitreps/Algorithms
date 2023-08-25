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
// this worked , what got me stuck was that , i only thought of the right most view, i didn't
// think of the nodes that would be visible even if there wasnt any right node for a parent.
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans; 
        if(root==NULL){
            return ans;
        }
        //ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false){
            int level;
            int n = q.size();
            bool take = true;
            for( int i = 0 ; i < n ; i++ ){
                TreeNode *temp = q.front(); 
                q.pop(); 
                if (i == n - 1) {  
                    ans.push_back(temp->val);
                }
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};
