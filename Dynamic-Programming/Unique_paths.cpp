#include <bits/stdc++.h>
// attempt1: getting overflow.
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
#define pb push_back
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;

void kev(int m,int n,int row,int col,int &ans){
   if(m==row && n==col){
      ans += 1;
      return;
   }
   if(m<row){
      m += 1;
      kev(m,n,row,col,ans);
      m -= 1;
   }
   if(n<col){
      n += 1;
      kev(m,n,row,col,ans);
      n -= 1;
   }
   if(m<row && n<col){
      n++;
      kev(m,n,row,col,ans);
      n--;
   }
   if(n<col && m<row){
      m++;
      kev(m,n,row,col,ans);
      m--;
   }
}  

int main(){
   int m;int n;
   cin>>m>>n;
   int ans =0;
   map<pair<int,int>,bool> mp;
   kev(0,0,m,n,ans);
   cout<<ans;
}
