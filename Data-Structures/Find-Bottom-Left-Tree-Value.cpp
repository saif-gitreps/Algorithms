/*
   The intuition was right, except that i forgot to use address for left_node
 */
class Solution {
public:
    int depth = 0;

    void dfs(TreeNode *root, int &left_node,int curr_depth, bool is_left){
        if(root == NULL){
            return;
        }
        if(is_left){
            if(curr_depth > depth){
                left_node = root -> val;
                depth = curr_depth;
            }
        }
        dfs(root -> left, left_node, curr_depth + 1, true);
        dfs(root -> right, left_node, curr_depth + 1, false);
    }
    int findBottomLeftValue(TreeNode* root) {
        int left_node = root -> val;
        int depth = 0;
        dfs(root, left_node, 0, true);
        return left_node;
    }
};


/*
  My idea was right, but apparently we had to find the node that is at the most depth and not left only.
 */
class Solution {
public:
    int depth = 0;
    void dfs(TreeNode *root, int &left_node,int curr_depth){
        if(root == NULL){
            return;
        }
        
        dfs(root -> left, left_node, curr_depth + 1);
        dfs(root -> right, left_node, curr_depth + 1);
        
        
        if(curr_depth > depth){
            left_node = root -> val;
            depth = curr_depth;
        }
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int left_node = root -> val;
        int depth = 0;
        dfs(root, left_node, 0);
        return left_node;
    }
};


/*
   Revisited after 28 days and solved it.
   
*/
class Solution {
public:
    void dfs(TreeNode* root, int curr_level, int &max_level, int &ans) {
        if (root == NULL) {
            return;
        }
        if (curr_level > max_level) {
            ans = root -> val;
            max_level = curr_level;
        }
        dfs(root -> left, curr_level + 1, max_level, ans);
        dfs(root -> right, curr_level + 1, max_level, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = root -> val, max_level = 0;
        dfs(root, 0, max_level, ans);

        return ans;
    }
};
