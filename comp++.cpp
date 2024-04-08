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
/* To build a complete binary tree, if an array was 1 2 3 4 5 6 7,
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


   int minScoreTriangulation(vector<int>& values) {
        set<vector<int>> st;
        multiset<int> sums;
        int n = 0;
        for(int i = 0; i < values.size(); i++){
            for(int j = 0; j < values.size(); j++){
                for(int k = 0; k < values.size(); k++){
                    
                    vector<int> indexes = {i, j, k};
                    sort(indexes.begin(), indexes.end());
                    
                    if(!st.count(indexes) && i != j && j != k && k != i){
                        sums.insert(
                            values[i] * values[j] * values[k]
                        );

                        st.insert(indexes);
                    }
                }
            }
        }
        
        for(auto s : st){
             for(auto k : s){
                  cout << k << " ";
             }
             cout << "\n";
        }

        for(auto s : sums) {
            cout << s << " ";
        }

        return 1;
    }





int main(){
   vector<vector<int>> a(5);

   cout << 2 / 2;

   

}
