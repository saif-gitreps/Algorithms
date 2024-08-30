class Solution {
// I mean, it works but not the best solution. IDK why the leetcode Complexity Analizer says its O(N). But actual
// Big O is O(n^2), SC is O(N).
public:
    int ans = 0;
    unordered_map<TreeNode*, TreeNode*> mp;
    void dfs1(TreeNode *root, TreeNode *parent, vector<TreeNode*> &leaf_nodes) {
        if (root == NULL) {
            return;
        }

        if (parent != NULL) {
            mp[root] = parent;
        }

        if (root -> left == NULL && root -> right == NULL) {
            leaf_nodes.push_back(root);
            return;
        }

        dfs1(root->left, root, leaf_nodes);
        dfs1(root->right, root, leaf_nodes);
    }

    void dfs2(TreeNode *root,int depth,int distance, unordered_map<TreeNode*, bool> &vis) {
        if (root == NULL || vis[root] || depth > distance) 
            return;
        
        vis[root] = true;

        if (root -> left == NULL && root -> right == NULL && depth > 0 && depth <= distance) ans++;

        if (mp.find(root) != mp.end() && vis.find(mp[root]) == vis.end())
            dfs2(mp[root], depth + 1, distance, vis);

        if (vis.find(root -> left) == vis.end())
            dfs2(root -> left, depth + 1, distance, vis);

        if (vis.find(root -> right) == vis.end())
            dfs2(root -> right, depth + 1, distance, vis);
    }
    
    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> leaf_nodes;
        dfs1(root, NULL, leaf_nodes);

        for (auto leaf_node : leaf_nodes) {
            unordered_map<TreeNode*, bool> vis;
            dfs2(leaf_node, 0, distance, vis);
        }

        return ans / 2;
    }
};



class Solution {
// check neetcode's first solution for the explanation.
// TC O(N^3).
public:
    // length of arr received by parent of a leaf means that parent has that many leaf nodes.
    int ans = 0;
    vector<int> dfs(TreeNode* root, int distance) {
        if (root == NULL) 
            return {};
        
        if (root -> left == NULL && root -> right == NULL) 
            return {1};
        
        vector<int> left_arr = dfs(root -> left, distance);
        vector<int> right_arr = dfs(root -> right, distance);

        for (auto d1 : left_arr) {
            if (d1 > distance) 
                continue; 
            for (auto d2 : right_arr) {
                if (d1 + d2 <= distance)
                    ans++;
            }
        }

        int left_arr_orig_size = left_arr.size();
        
        for (int i = 0; i < right_arr.size(); i++) {
            right_arr[i] += 1; 
            left_arr.push_back(right_arr[i]);
        }
        
        for (int j = 0; j < left_arr_orig_size; j++)
            left_arr[j] += 1; 
        
        return left_arr;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
};


class Solution {
// Time Complexity: O(n * distance^2)
public:
    vector<int> dfs(TreeNode* root, int distance, int& result) {
        if (!root) return {};
        if (!root->left && !root->right) return {1};
        
        vector<int> left = dfs(root->left, distance, result);
        vector<int> right = dfs(root->right, distance, result);
        
        result += countPairs(left, right, distance);
        
        vector<int> ret;
        for (int i : left) {
            if (i + 1 < distance) ret.push_back(i + 1);
        }
        for (int i : right) {
            if (i + 1 < distance) ret.push_back(i + 1);
        }
        return ret;
    }
    
    int countPairs(vector<int>& left, vector<int>& right, int distance) {
        int count = 0;
        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) count++;
            }
        }
        return count;
    }
    
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }
};
