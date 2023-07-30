#include <bits/stdc++.h>
//for_each(a.begin(),a,end(),personalFunc())
/* paste board:
*/
using namespace std;
#define s(x) sizeof(x)/sizeof(x[0]);
#define ll long long int
#define DBG(x) cout << #x << " " << x << "\n"
#define newline() "\n"
#define nexline() std::cout<<newline()
#define cyes std::cout<<"YES"<<newline()
#define cno std::cout<<"NO"<<newline()
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
const int MAXN = 100005;

int GCD(int a,int b){return b==0?a:GCD(b,a%b);}
int LCM(int a,int b){return (a*b)/GCD(a,b);}

class tree{
public:
   int data;
   tree *left;
   tree *right;
};

tree *get_node(int n){
   tree *newnode = new tree();
   newnode->data = n;
   newnode->left = NULL;
   newnode->right = NULL;
   return newnode;   
}

void preorder(tree *root){
   if(root!=NULL){
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
   }
}

void inorder(tree *root){
   if(root!=NULL){
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
   }
}

void postorder(tree *root){
   if(root!=NULL){
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
   }
}

tree *insert_bs(tree *root,int n){
   if(root==NULL){
      root = get_node(n);
   }
   else{
      if(root->data>=n){
         root->left = insert_bs(root->left,n);
      }
      else{
         root->right = insert_bs(root->right,n); 
      }
   }
return root;}


void solve(){
   int t,count = 0,i = 0,mark=0;
   ll sx,sy,ex,ey;
   cin>>t>>sx>>sy>>ex>>ey;
   string dir;
   cin>>dir;
   for(i=0;i<dir.size();i++){
      if(dir[i]=='N'){
         if((sy+1)<=ey)sy++;
      }
      else if(dir[i]=='S'){
         if((sy-1)>=ey)sy--;
      }
      else if(dir[i]=='W'){
         if((sx-1)>=ex)sx--;
      }
      else if(dir[i]=='E'){
         if((sx+1)<=ex)sx++;
      }
      if(sx==ex && sy==ey){
         cout<<i+1<<newline();
         return;
      }
   }
   cout<<-1;

}

int main(){
	ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   solve();
}

