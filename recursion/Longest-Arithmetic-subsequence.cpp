//attempt 1 . kind of bruteforcing everything.
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

void kev(int i,vector<int> a,stack<int> &s,unordered_map<int,int> &mp){
   if(i>=a.size()){
      return;
   }
   if(s.size()==2){
      int num1 = s.top();s.pop();
      int num2 = s.top();s.pop();
      int diff = abs(num1-num2);
      mp[diff]++;
      s.push(num2);
      s.push(num1);
      return;
   }
   for(int j=i;j<a.size();j++){
      s.push(a[j]);
      kev(i+1,a,s,mp);
      s.pop();
   }
}

int main(){
   vector<int> a = {20,1,15,3,10,5,8};
   unordered_map<int,int> mp;
   stack<int> s;
   kev(0,a,s,mp);
   int mx = 0;
   for(auto x:mp){
      mx = max(x.second,mx);
   }
   cout<<mx<<" ";
}
