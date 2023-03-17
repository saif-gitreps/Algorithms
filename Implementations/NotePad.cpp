#include <bits/stdc++.h>
using namespace std;
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;
// this is the first attempt, did work til 29th sub test case of 2.
// not a consistent one but this was the idea i came up with.

void solve(){
   int n; cin>>n;
   string s; cin>>s;
   map<string,bool> m;
   for(int i=0;i<s.size();){
      string p = "";
      p += (s[i]);
      p +=  s[i+1];
      if(m[p]!=true){
         m[p] = true;
      }
      else{
         cout<<"YES\n"; return;
      }
      if(i+2<s.size()){ i+=2;}
      else {i++;}
   }
   cout<<"NO\n";
}

void solve_2(){
  // okay so my concept was right, 
  // the difference is , i should have iterated with 1 interval.
  // and i should have checked if (i+1,i+2) index ahead substring was true or no.
    int n; cin>>n;
   string s; cin>>s;
   map<string,bool> m;
   for(int i=1;i<s.size();i++){
      string p = "";
      p += (s[i-1]);
      p +=  s[i];
      m[p] = true;
      if(i+2<n){
         string p = "";
         p += (s[i+1]);
         p +=  s[i+2];
         if(m[p]){
            cout<<"YES\n";return;
         }
      }
   }
   cout<<"NO\n";
}


int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve_2();
}

