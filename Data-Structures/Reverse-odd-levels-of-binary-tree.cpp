class Solution {
public:
    void dfs2(TreeNode* root, int level, unordered_map<int, vector<int>> &mp) {
        if (!root) {
            return;
        }
        
        if (level % 2 == 1) {
            root->val = mp[level].back();
            mp[level].pop_back();
        }

        dfs2(root->left, level + 1, mp);
        dfs2(root->right, level + 1, mp);
    }
    void dfs1(TreeNode* root, int level, unordered_map<int, vector<int>> &mp) {
        if (!root) {
            return;
        }
        
        if (level % 2 == 1) {
            mp[level].push_back(root->val);
        }

        dfs1(root->left, level + 1, mp);
        dfs1(root->right, level + 1, mp);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        unordered_map<int, vector<int>> mp;
        dfs1(root, 0, mp);
        dfs2(root, 0, mp);
        return root;
    }
};

// clever solution, try to use your finger and choose a tree by keeping track of pointers instead of one.
class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        // We call the function from lvl 0, and everything starts from lvl 1
        traverse(root.left, root.right, 1);
        return root;
    }

    public void traverse(TreeNode node1, TreeNode node2, int lvl) {
        if (node1 == null || node2 == null) {
            return;
        }
        if (lvl % 2 == 1){
            int temp = node1.val;
            node1.val = node2.val;
            node2.val = temp;
        }

        traverse(node1.left, node2.right, lvl + 1);
        traverse(node1.right, node2.left, lvl + 1);
    }
}
