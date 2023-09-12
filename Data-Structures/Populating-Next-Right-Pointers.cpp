/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
// attempt 1 : idea was to use bfs and connect each nodes in a loop.
// only first node is taken , idk why the other nodes arent linked.
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while(q.empty() == false){
            int size = q.size();
            Node *curr = NULL;
            for(int i = 1 ; i <= size; i ++){
                Node *node1 = q.front(); q.pop();
                if(!node1->left) q.push(node1->left);
                if(!node1->right) q.push(node1->right);

                if(curr == NULL){
                    curr = node1;
                }
                else if(curr != NULL){
                    curr -> next = node1;
                    curr = node1;
                    curr -> next = NULL;
                }
            }
        }
        return root;
    }
};
