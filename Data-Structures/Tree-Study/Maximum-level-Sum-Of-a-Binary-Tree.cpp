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
    int maxLevelSum(TreeNode* root) {
        int mx = INT_MIN;
        int level = 1;
        int max_level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false){
            int sum = 0;
            int size = q.size();
            for(int i = 0 ; i < size; i++){
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            if(sum > mx){
                mx = sum;
                max_level = level;
            }
            level++;
        }
        return max_level;
    }
};
