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
// used preorder trav instead ,works.
public:
    unordered_set<int> s;
    void dfs_preorder(TreeNode* root,int t){
      if(root==NULL){
        return;
      }
      root->val = t;
      s.insert(t);
      dfs_preorder(root->left,(2 * t + 1));
      dfs_preorder(root->right,(2 * t + 2));
    }
    FindElements(TreeNode* root) {
      if(root!=NULL){
        root->val = 0;
        s.insert(root->val);
      }
      dfs_preorder(root,0);
      
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
// i could have used the preorder method of searching , i just didnt know how to get the reference of the tree
// lesson learned , i have to use dfs with tree
public:
    FindElements(TreeNode* root) : root(root) {
        decontaminate(root, 0);
    }

    bool find(int target) {
        return preorder_search(root, target);
    }

private:
    TreeNode* root;

    void decontaminate(TreeNode* node, int value) {
        if (node) {
            node->val = value;
            decontaminate(node->left, 2 * value + 1);
            decontaminate(node->right, 2 * value + 2);
        }
    }

    bool preorder_search(TreeNode* node, int target) {
        if (node) {
            if (node->val == target) return true;
            return preorder_search(node->left, target) || preorder_search(node->right, target);
        }

        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
