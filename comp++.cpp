#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
const int N = 1e5 + 10;
vector<vector<int>> g(N);
vector<bool> visit(N);
vector<int> level(N);

int arrayBasedUniqueKeyGenerate(vector<int> options){
         int key = 0;
        for(auto opt: options){
            key <<= 1;
            if(!opt){
                key |= 1;
            }
        }
       return key = (int)key;
}

class TreeNode {
public:
   int val;
   TreeNode *left;
   TreeNode *right;
   
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildBSTree(vector<int>& nums, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBSTree(nums, start, mid - 1);
    root->right = buildBSTree(nums, mid + 1, end);

    return root;
}

TreeNode * buildTree(vector<int> a,int i){
/* 
    To build a complete binary tree, if an array was 1 2 3 4 5 6 7,
    our tree would be :
        1
       / \
      2   3
     / \ / \
    4  5 6  7

 */
   if(i >= a.size()){
      return NULL;
   }
   TreeNode *root = new TreeNode(a[i]);
   root->left = buildTree(a,2 * i + 1);
   root->right = buildTree(a,2 * i + 2);
   return root;
}

vector<int> preTraversedArray;

void preOrder(TreeNode *root){
   if(root==NULL){
      return;
   }
   preTraversedArray.push_back(root->val);
   preOrder(root->left);
   preOrder(root->right);
}

void inOrder(TreeNode *root){
   if(root==NULL){
      return;
   }
   inOrder(root->left);
   preTraversedArray.push_back(root->val);
   inOrder(root->right);
}


vector<vector<int>> levelTraversedArray;

void levelOrder(TreeNode* root){
   queue<TreeNode*> q;
   q.push(root);
   while(q.empty() == false){
      int size = q.size();
      vector<int> level;
      for(int i = 0 ; i < size ; i ++){
         TreeNode *current_node = q.front();
         q.pop();
         if(current_node->left != NULL){
            q.push(current_node->left);
         }
         if(current_node->right != NULL){
            q.push(current_node->right);
         }
         level.push_back(current_node->val);
      }
      levelTraversedArray.push_back(level);
   }
}

class Student{

private:
    int x;
    int y;

public:
    int z = 10;
    Student(int x, int y){
        this -> x = x;
        this -> y = y;
    }

    int getX(){
        return this -> x;
    }

    void setX(int x){
        this -> x = x;
    }

};


/*

    three methods of Disjont Set Union.
    - make() -> will a add a new indivual node. example 2<-4 5<-6,
    adding make(8) will result in 2<-4, 5<-6 , 8
    
    - find() -> this will return the head of a union , we pass in any child or root 
    as a param. Example: 2<-4, 5<-6, 8, find(4) is 2 (the root of this set).

    - union() -> this will join heads for two diff sets, examples:
    2<-4 and 5<-6 will be joined as :
    2 <- 5
    ^    ^
    |    |
    4    6

    TC is amortorized O(alpha(n)) [alpha(n) reverse ackerman function]
    ackerman function basically says it grows slowly.

    So overall operation cost is almost Constant time.


*/

const int Ne = 100000; 
int parent[Ne];
int size[Ne];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if (v == parent[v]) {
        return v;
    }
    // instead of this-> return find(parent[v]);
    // we will do an extra step of path compression.
    // ultimately at the end of recursion we will receive the root
    // so it will backtrack and set every children on that tree to have parent of 
    // returned root. 
    parent[v] = find(parent[v]);
}

void Union(int a, int b){
    // step 1: find the root of each nodes.
    a = find(a);
    b = find(b);

    // step 2: If their roots are same that means they already joined sets.
    if(a == b){
        return;
    }

    // step 3: Make parent of b as a, a <- b (b is pointing to its parent).
    // We always make sure to join the largest tree is on the left, and smallest on the right.
    if(size[a] < size[b]){
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];

}

int kev(int i,const vector<int> &a){
    if(i >= a.size()){
        return 0;
    }
    
    int sum = 0, ans = 0, n = a.size() - 1;
    
    for(int k = i; k < min(i + 3, n); k++){
        sum += a[k];
        ans = max(ans, sum + min({
            kev(i + k + 1, a),
            kev(i + k + 2, a),
            kev(i + k + 3, a)
        }));
    }

    return ans;
}
string stoneGameIII(vector<int>& stone) {
    int sum = 0; 
    for(auto s : stone) sum += s;
    int ans = kev(0, stone);

    debug(ans);
    
    if(ans > sum - ans){
        return "Alice";
    } 
    else if(ans == sum - ans){
        return "Tie";
    }
    else{
        return "Bob";
    }
}


int main() {
    vector<int>  a = {-1,-2,-3};
    cout << stoneGameIII(a);
    return 0;
}

