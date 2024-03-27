/**
  create a queue, and store all the nodes where any of the child slots are empty
  Do an initial bfs for that.

  For getting the parent node, whichever is empty on the left will be on top of the queue,
  if the right is filled after inserting , then we pop it.
    
 */
class CBTInserter {
public:
    TreeNode *root;
    queue<TreeNode*> main_q;

    void bfs(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left == NULL || node->right == NULL){
                main_q.push(node);
            }

            // if they have a children
            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);
        }
    }

    CBTInserter(TreeNode* r) {
        root = r;
        bfs(root);
    }

    int insert(int val) {
        TreeNode *newNode = new TreeNode(val);
        TreeNode *src = main_q.front();

        if(src -> left == NULL){
            src->left = newNode;
        }
        else{
            src->right = newNode;
            main_q.pop();
        } 
        main_q.push(newNode);
        return src -> val;
    }
    
    TreeNode* get_root() {
        return root;   
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
