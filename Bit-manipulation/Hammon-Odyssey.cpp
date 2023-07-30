#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
https://codeforces.com/contest/1847/problem/B

void solve(){
  int n;
   cin >> n;
   int arr[n];
   for(int i = 0; i < n; i++)cin >> arr[i];
   int cur = arr[0];
   int part = 1;
   for(int i = 0; i < n; i++){
      cur &= arr[i];
      if(cur == 0){
         if(i == n-1)break;
         part++;
         cur = arr[i + 1];
      }
   }
   if(cur != 0)part--;
   part = max(part,1);
   cout << part << '\n';
}


int main(){
   int t; cin>>t; while(t--)
   solve(); 
}
 
