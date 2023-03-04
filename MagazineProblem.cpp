#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
#define out_arr(x,n) for(int i=0;i<n;i++)cout<<x[i]<<" " 
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
#define pb push_back
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;
 
void solve(){
   int n;cin>>n;
   string s; cin>>s;
   int a[n],prev =0,res=0;
   for(int i=0;i<n;i++){
      cin>>a[i];
      if(s[i]=='0'){
         prev = a[i];
      }
      else{
         if(a[i]>prev){
            res += a[i];
         }
         else{
            res += prev;
            prev= a[i];
         }
      }
   }
   cout<<res<<newline();
}
 
int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}
