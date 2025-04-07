
class Solution {
// logical attempt but didnt work.
public:
    void dfs(TreeNode* root, int current_depth, int &depth, TreeNode*& ans, TreeNode *parent) {
        if (root == NULL) return;
        
        if (current_depth > 1 && current_depth > depth && parent != NULL) {
            ans = parent;
            depth = current_depth;
        }
        
        dfs(root->left, current_depth+1, depth, ans, root);
        dfs(root->right, current_depth+1, depth, ans, root);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans = new TreeNode();
        ans = root;
        int depth = 0;
        dfs(root, 0, depth, ans, NULL);
        return ans;
    }
};

class Solution {
public:
    TreeNode* ans = nullptr;
    int deepest = 0;

    int dfs(TreeNode* root, int depth) {
        if (!root) return depth;

        int left = dfs(root->left, depth + 1);
        int right = dfs(root->right, depth + 1);

        deepest = max(deepest, max(left, right));

        if (left == deepest && right == deepest) {
            ans = root;
        }

        return max(left, right);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
