#include <bits/stdc++.h>
using namespace std;
#define s(x) sizeof(x)/sizeof(x[0])
#define ll long long int
#define newline() "\n"
#define nexline() std::cout<<newline()
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
#define out_arr(x,n) for(int i=0;i<n;i++)cout<<x[i]<<" " 
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
#define pb push_back
#define pf push_front
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;

void solve(){
   int n;cin>>n; ll a[n] = {0};   
   for(int i=0;i<n;i++) {cin>>a[i];}
   ll b[n] = {};
   b[0] = a[0];
   for(int i=1;i<n;i++){
      b[i] = b[i-1]+a[i];
   }
   ll mx = -1,start=0,end=b[n-1];
   for(int i=0;i<n-1;i++){
      start += a[i]; end -= a[i];
      mx = max(__gcd(start,end),mx);
   }
   cout<<mx<<newline();
}
 
int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}
 
