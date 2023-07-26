#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
const int MAXN = 100010;
ll LCM(ll a,ll b){
   return (a*b)/__gcd(a,b);
}

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

int pow_large(int a,int b){
   int res = 1;
   while(b>0){
      if(b%2==1){
         res *= a;
      }
      a *= a;
      b /= 2;
   }
   return res;
}
vector<int> find_factors(int n){vector<int> f;
for (int x=2;x*x<=n;x++)
{while(n%x==0) {f.push_back(x);n /= x;} }
if (n > 1) f.push_back(n);return f; }

int main(){
   int n;cin>>n;
   string s;cin>>s;
   string fb = "";
   for(int i=1;i<=700;i++){
      if(i%3==0){
         fb+='F';
      }
      if(i%5==0){
         fb +='B';
      }
   }
   size_t pos = fb.find(s);
   if(pos!=string::npos){
      cout<<"YES\n";
   }
   else{
      cout<<"NO\n";
   }
   cout<<pow_large(3,4);
}
