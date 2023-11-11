// passed 78/135 cases.
class Solution {
public:
    int kev(TreeNode * root, int ts, int sum){
        if(root == NULL){
            return 0;
        }
        if(sum + root->val == ts){
            return 1;
        }
        int leftpick = 0;int leftnot = 0;
        int rightpick = 0; int rightnot = 0;
        leftpick = kev(root->left, ts, sum + root->val);
        leftnot = kev(root->left, ts, sum);
        rightpick = kev(root->right, ts, sum + root->val);
        rightnot = kev(root->right, ts, sum);
        return leftpick+leftnot+rightpick+rightnot;
    }
    int pathSum(TreeNode* root, int targetSum) {
        return kev(root, targetSum, 0);
    }
};
