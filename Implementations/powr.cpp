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
//ygonepiece's code.

bool canJump(vector<int>& nums) {
      int i=nums[0],n = nums.size();
      if(n==1){
         return true;
      }
      while(1){
            if(nums[i]==0){
                break;
            }
            i += nums[i];
            if(i>=n){
               break;
            }
        }
        if(i>=n-1){
            return true;
        }
        else{
            return false;
        }   
    }

void solve(){
   int n; cin>> n; vector<int> a;
   for(int i=0;i<n;i++){
      int x ; cin>> x; 
      a.push_back(x);
   }
   cout<<canJump(a);
   
}

int main(){
   FAST(SUIII);
   //int t;cin>>t;while(t--)
   solve();
}

