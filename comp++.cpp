#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define nexline() std::cout<<newline()
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
#define out_arr(x,n) for(int i=0;i<n;i++)cout<<x[i]<<" " 
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
#define pb push_back
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;
ll LCM(ll a,ll b){return (a*b)/__gcd(a,b);}
vector<int> seevey_boy(int n){ 
   vector<int> a;
   vector<bool> is_prime(n+1, true);
   is_prime[0] = is_prime[1] = false;
   for (int i = 2; i <= n; i++) {
      if (is_prime[i] && (long long)i*i <= n) {
         for (int j = i*i; j <= n; j += i){
            is_prime[j] = false; } 
         } 
      }
   for(int i=2;i<=n;i++){if(is_prime[i]){
         a.pb(i);
      }
   }   
   return a;
}
/*             ::Pasteboard::
===========================================

//===========================================*/

void solve(){
   int n;cin>>n;
   ll a[n],mx = -(GGG);
   map<ll,int> b;
   for(int i=0;i<n;i++){
      cin>>a[i];
      b[a[i]]++;
      ll c = b[a[i]];
      mx=  max(mx,c);
   }
   sort(a,a+n);
   ll curr = a[0],count=0,in_check=0;
   for(int i=1;i<n;i++){
      if(curr==a[i] && mx){
         count++;
         mx--;
         in_check = 0;
      }
      else if(abs(curr-a[i])==1){
         curr= a[i];
         in_check++;
      }
      else if(abs(curr-a[i])>=2){
         curr = a[i];         
         count++;
         in_check = 0;
      }

   }
   if(in_check==n-1){
      cout<<1<<newline();
   }
   else{
      cout<<count<<newline();
   }
}

int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}

