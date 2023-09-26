class Solution {
// [2,1,3,null,4]-> op : 6, ex: 7 , da hell is this test case ?????????????
public:
    int rob(TreeNode* root) {
        if(root->left == NULL && root->right == NULL){
            return root->val;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while(q.empty() != true){
            int size = q.size();
            int sum = 0;
            for(int i = 1 ; i <= size; i ++){
                TreeNode *node = q.front(); q.pop();
                sum += node->val;
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            level.push_back(sum);
        } 
        int n = level.size();
        int prev = 0;
        int curr = level[0];
        for(int i = 1; i < n ; i ++){
            int pick = level[i] + prev;
            int not_pick = curr;
            prev = curr;
            curr = max(pick , not_pick);
        }
        return curr;
    }
};
