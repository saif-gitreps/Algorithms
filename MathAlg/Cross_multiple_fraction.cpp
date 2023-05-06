#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
#define out_arr(x,n) for(int i=0;i<n;i++)cout<<x[i]<<" " 
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;

void solve(){
   ll a,b,c,d;
   cin>>a>>b>>c>>d;
   //case1:if the cross product == to each other then 0.
   if((a*d)==(c*b)) {
      cout<<0<<newline();
      return;
   }
   //case2:if either of cross product mods to 0 then 1/
   ll crossA = a*d;
   ll crossB = b*c; 
   if((crossB!=0 && (crossA%crossB==0)) || (crossA!=0 && (crossB%crossA==0))){
      cout<<1<<newline();
   }
   else{
      //case3: else its 2 only.
      cout<<2<<newline();
   }

}  

int main(){
   FAST(SUIII);
   int t; cin>>t; while(t--)
   solve();
}
 
