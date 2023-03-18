#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define out_arr(x,n) for(int i=0;i<n;i++)cout<<x[i]<<" "
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);

//solution worked but time limit exceeded.

void solve(){
   int n; cin>>n ;
   ll a[n],b[n],c[n];
   for(int i=0;i<n;i++){
      cin>>b[i];
   }
   for(int i=0;i<n;i++){
      cin>>a[i];
      c[i] = a[i];
   }
   
   for(int i=0;i<n;i++){
      if(i==0){
         for(int j=0;j<n;j++){
      
             a[j] = min(a[j],b[j]);
             b[j] -= a[j];
           
         }
      }
      else{
         for(int j = i;j<n;j++){
            a[j] = a[j] + min(b[j-i],c[j]);
            if(b[j-i]-c[j]<=0){
               b[j-i] = 0;
            }
            else{
               b[j-i]  -= c[j];
            }
         }
      }
   }
   out_arr(a,n);
   cout<<"\n";
}

int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}

