#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
#define GGG 9223372036854775807
#define pb push_back
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;
/*
so the three conditions were 
1: if there were no one , then YES we can get all mod to 0.
2: if there is a 1 but no consective numbers i.e abs(a[0]-a[1])==1 then YES.
3: if there is a 1 and two consecutive numbers then NO.
*/
void solve(){
   int n;cin>>n;
   ll a[n] = {};
   int yes= false;
   for(int i=0;i<n;i++){
      cin>>a[i];
      if(a[i]==1) yes =true;
   }
   sort(a,a+n);
   if(yes){
      for(int i=1;i<n;i++){
         if(abs(a[i-1]-a[i])==1){
            cout<<"NO\n"; return;
         }
      }
   }
   cout<<"YES\n";  
   
}

int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}

