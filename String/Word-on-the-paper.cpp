#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
https://codeforces.com/problemset/problem/1850/C

void solve(){
  string s;
  string ans = "";
  for(int i=0;i<8;i++){
   cin>>s;
   for(int i=0;i<s.size();i++){
      if(s[i]!='.'){
         ans+=s[i];
      }
   }
  }
  cout<<ans<<"\n";

}


int main(){
   int t; cin>>t; while(t--)
   solve(); 
}
 
