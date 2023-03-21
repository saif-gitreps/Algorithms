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
   long long a,b,c;
   cin>>a>>b>>c;
   /*case 1: so if a>c then we know that we 
   dont need to buy from a, cuz we get cheaper in bulk anyway plus more donuts.
   */
   if(a<c){
      cout<<1<<" ";
   }
   else{
      cout<<-1<<" ";
   }
   //case 2: we compare c with the bulk price of a*b for comparison , if we can get a(price)*b(donuts) cheaper than c(a box) then we choose it from a. else from b;
   if(a*b>c){
      cout<<b<<"\n";
   }
   else{
      cout<<-1<<"\n";  
   }
  //another thing i learned is , how to check if a fraction is greater than another 
  // so check 1/4 and 1/2 , which is greater, for that cross multiply and check.

}

int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}

