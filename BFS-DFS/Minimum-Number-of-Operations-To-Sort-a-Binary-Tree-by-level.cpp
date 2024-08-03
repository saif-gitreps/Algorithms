/*
  Please don't ask how I came up with the intuition. Just pulled it out of my ass,
  When you're rereading it, try to make a dry run of what I was trying to figure out.
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()) {
            int n = q.size();
            map<int, int> mp;
            unordered_map<int, int> mp2;
            
            for (int i = 0; i < n; i++) {
                mp[q.front() -> val] = i;
                mp2[i] = q.front() -> val;
                
                if (q.front() -> left) q.push(q.front() -> left);
                if  (q.front() -> right) q.push(q.front() -> right);
                q.pop();
            }

            int i = 0;
            for (auto [key, index] : mp) {
                if (index != i) {
                    count ++;
                    auto it = mp2.find(i);
                    
                    mp[it -> second] = index; 
                    mp[key] = i;
                    
                    mp2[index] = it -> second;
                    mp2[i] = key; 
                }
                i++;
            }
        }

        return count;
    }
};
