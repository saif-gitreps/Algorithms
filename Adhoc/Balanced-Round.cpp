#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
https://codeforces.com/contest/1850/problem/D

void solve(){
   int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];    
    sort(all(a));
    int cnt = 1, ans = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] - a[i - 1] > k) {
            cnt = 1;
        } else {
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << n - ans+1 << '\n';
}

int main(){
   
    int t; cin>>t; while(t--)
    solve(); 
}
==================================
   #include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
const int MAXN = 100010;
  
void solve(){
   int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];    
    sort(a.begin(),a.end());
    int cnt = 1, ans = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] - a[i - 1] > k) {
            cnt = 1;
        } else {
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << n - ans<< '\n';
}

int main(){
   
    int t; cin>>t; while(t--)
    solve(); 
}
 
