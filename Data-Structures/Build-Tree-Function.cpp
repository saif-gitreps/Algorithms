#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
const int N = 1e5 + 10;
vector<vector<int>> g(N);
vector<bool> visit(N);
vector<int> level(N);

class TreeNode {
public:
   int val;
   TreeNode *left;
   TreeNode *right;
   
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode * buildTree(vector<int> a,int i){
   if(i >= a.size()){
      return NULL;
   }
   if(a[i] == -1){
      return NULL;   
   }
   TreeNode *root = new TreeNode(a[i]);
   root->left = buildTree(a,2 * i + 1);
   root->right = buildTree(a,2 * i + 2);
   return root;
}

void preOrder(TreeNode *root){
   if(root==NULL){
      return;
   }
   cout << root->val << " -> ";
   preOrder(root->left);
   preOrder(root->right);
}

int main() {
   vector<int> a = {1,2,3,4,5,6};

   TreeNode *root = buildTree(a,0);

   preOrder(root);

}
 
