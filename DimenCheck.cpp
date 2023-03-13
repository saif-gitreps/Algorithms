#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define newline() "\n"
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
const int MAXN = 100010;
void solve(){
   bool yes1 = false,yes2 = false;
   int n,k;
   cin>>n>>k;
   while(n--){
      int l,r;
      cin>>l>>r;
      if(l==k)yes1 = true;
      if(r==k)yes2 = true;
   }
   if(yes1 && yes2){
      cout<<"YES"<<newline();
   }
   else{
      cout<<"NO"<<newline();
   }
}  
 
int main(){
	ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   solve();
}
 
