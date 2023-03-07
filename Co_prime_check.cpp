#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define nexline() std::cout<<newline()
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]

#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;

void solve(){
   int n;
   cin>>n;
   int a[1001] = {0};
   bool check = false;
   for(int i=1;i<=n;i++){
      int x;cin>>x;
      if(x%2!=0) {check=true;}
      a[x] = i; 
   }
   
   if(check==false){cout<<-1<<newline();return;}
 
   int first = -1,second = -1;
   for(int i=1,j;i<=1000;i++){
      for(j=1;j<=1000;j++){
         if(a[j]>0 && a[i]>0){
            if(__gcd(i,j)==1){
               first =max(a[i]+a[j],first);
            }
         }
      }
   }
   cout<<first<<newline();
}  
 
int main(){
   FAST(SUIII);
   int t; cin>>t; while(t--)
   solve();
}
