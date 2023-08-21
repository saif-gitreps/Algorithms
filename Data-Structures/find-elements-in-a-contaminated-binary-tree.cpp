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
class FindElements {
//getting SLE using BFS, idk why

public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
      if(root!=NULL){
        root->val = 0;
        s.insert(root->val);
      }
      queue<TreeNode*> q;
      q.push(root);
      while( q.empty() == false ){
        int n = q.size();
        TreeNode *temp = q.front();
        q.pop();
        for(int i = 0 ; i < n ; i++){
          if(temp->val >= 0){
            if(temp->left != NULL){
              temp->left->val = 2 * temp->val + 1;
              s.insert(temp->left->val);     
              q.push(temp->left);
            }
            if(temp->right != NULL){
              temp-> right->val = 2 * temp->val + 2;
              s.insert(temp->right->val);
              q.push(temp->right);
            }
          } 
        }
      }
    }
    int pre(TreeNode *root,int target){
      return 0;
    }
    
    bool find(int target) {
      return s.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
