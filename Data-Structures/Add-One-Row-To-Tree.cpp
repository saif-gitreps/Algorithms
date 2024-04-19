class Solution {
// just simulated it. and it worked.
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode; 
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        bool flag = false;
        
        while(!q.empty()  && !flag){
            int size = q.size();
            
            for(int i = 1 ; i <= size; i++){
                TreeNode* node = q.front(); q.pop();
                if(level == depth - 1){
                    TreeNode* leftNode = node -> left;
                    TreeNode* rightNode = node -> right;
                    
                    TreeNode* newRightNode = new TreeNode(val); 
                    TreeNode* newLeftNode = new TreeNode(val);
                    
                    newLeftNode -> left = leftNode;
                    newRightNode -> right = rightNode;
                    
                    node -> left = newLeftNode;
                    node -> right = newRightNode;
                    flag = true;
                }
                else{
                    if (node->left != NULL) {
                        q.push(node->left);
                    }
                    if (node->right != NULL) {
                        q.push(node->right);
                    }
                } 
            }
            level = level + 1;
        }
        return root;
    }
};


// Genius solution just by using recursion. if 
TreeNode* addOneRow(TreeNode* root, int val, int depth,bool is_left=true) {
        if(depth==1) {
            TreeNode *newnode = new TreeNode(val);
            
            if(is_left) {
                newnode->left = root;
                newnode->right = NULL;
            }
            else {
                newnode->right = root;
                newnode->left = NULL;
            }
            return newnode;
        }
  
        if(root) {
            root->left = addOneRow(root->left,val,depth-1);
            root->right = addOneRow(root->right,val,depth-1,false);
        }
        return root;
    }
 
