#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;
/*
sol is basically to run a two point on a sorted array 
but from 0 and 1 , instead of the traditional 0 and n-1 ,
and check if there exists two number where diff==K(our number).
*/

void solve(){
   int n;
   ll k;
   cin>>n>>k;
   ll a[n] = {},sum =0;
   bool yes = false;
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   sort(a,a+n);
   int start = 0, end = 1;
   while(start<n && end<n){
      if(abs(a[start]-a[end])==k){
         cout<<"YES\n";return;
      }
      else if(abs(a[start]-a[end])<k){
         end++;
      }
      else if(abs(a[start]-a[end])>k){
         start++;
      }
   }
   cout<<"NO\n";
}

int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}

