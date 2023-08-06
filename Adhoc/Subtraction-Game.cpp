https://codeforces.com/contest/1844/problem/A

#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
  
void solve(){
   int a,b;
   cin>>a>>b;
   if(a>=2){
      cout<<1<<"\n";return;
   }
   else if(a==1 && b>=3){
      cout<<2<<"\n";return;
   }
   else if(a==1 && b==2){
      cout<<3<<"\n";return;
   }
}

int main(){
   
    int t; cin>>t; while(t--)
    solve(); 
}
 
