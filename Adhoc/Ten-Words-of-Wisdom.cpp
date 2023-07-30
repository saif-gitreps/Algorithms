#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
  

void solve(){
  int n;cin>>n;
  int mx = -1;
  int ind =1;
  int i;
  for(i=1;i<=n;i++){
   int a,b;
   cin>>a>>b;
   if(a<=10){
      if(b>mx){
         mx = b;
         ind = i;
      }
   } 
  }
  cout<<ind<<"\n";

}


int main(){
   int t; cin>>t; while(t--)
   solve(); 
}
 
