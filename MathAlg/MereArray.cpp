#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define GGG 9223372036854775807
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;
//ygonepiece's code.
 
void solve(){
   int n; cin>> n;
   ll a[n] = {},b[n]={};
   ll mn = GGG;
   for(int i=0;i<n;i++){
      cin>>a[i]; mn = min(mn,a[i]);
      b[i] = a[i];
   }
   if(n==1){
      cout<<"YES\n";return;
   }
   sort(b,b+n);
   int k = 0;
   for(int i=0;i<n;i++){
      if(a[i]!=b[i] && a[i]%mn!=0){
         k = 1;
      }
   }
   cout<<(k?"NO\n":"YES\n");
 
 
}
 
int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}
