#include <bits/stdc++.h>
// donno why it is not working .
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
  
void solve(){
   int n,k;
   cin>>n>>k;
   vector<long long> a;
   long long ans = 0;
   for(int i=0;i<n;i++){
      long long x; cin>>x;
      a.push_back(x);
      ans+=a[i];
   }
   sort(a.begin(),a.end());
   int start=0,end=n-1;
   while(start<=end && k){
      if(a[start]+a[start+1]<=a[end] && k && start+1<end){
         ans -= a[start];
         ans -= a[start+1];
         k--;
         start+=2;
      }
      else if(a[start]+a[start+1]>a[end] && k){
         ans -= a[end];
         end--;
         k--;
      }
   }
   cout<<"ANS HERE _>"<<ans<<"\n";
}

int main(){  
    int t; cin>>t; while(t--)
    solve(); 
}

#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
  
void solve(){
   int n, k; cin >> n >> k;
 
        vector<int> a(n);
        for (auto &i : a) cin >> i;
 
        sort(a.begin(), a.end());
 
        vector<long long> psum(n + 1);
        for (int i = 0; i < n; ++i) {
            psum[i + 1] = psum[i] + a[i];
        }
 
        long long answer = 0;
        for (int i = 0; i <= k; ++i) {
            answer = max(answer, psum[n - i] - psum[2 * (k - i)]);
        }
 
        cout << answer << "\n";
}

int main(){  
    int t; cin>>t; while(t--)
    solve(); 
}
 
