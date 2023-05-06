#include <bits/stdc++.h>
#define newline() "\n"

void solve(){
   ll a,b,c,d;
   cin>>a>>b>>c>>d;
   if(a!=0){
      cout<<a+min(b,c)*2+min(a+1,abs(b-c)+d)<<newline();
   }
   else{
      cout<<1<<newline();
   }
}
 
int main(){
	ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
      solve();
   }
}
