#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
https://codeforces.com/contest/1822/problem/B  

void solve(){
   int n;cin>>n;
   vector<long long> a;
   for(int i=0;i<n;i++){
      long long x; cin>>x;
      a.push_back(x);
   }
   sort(a.begin(),a.end());
   cout<<((a[0]*a[1]>a[n-1]*a[n-2])?a[0]*a[1]:a[n-1]*a[n-2])<<"\n";
}


int main(){
   int t; cin>>t; while(t--)
   solve(); 
}
 
