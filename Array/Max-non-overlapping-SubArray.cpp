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

void rev()

int maxNonOverlapping(vector<int>& nums, int target) {
   if(nums.size()==1 && nums[0]==target){
      return nums.size();
   }
   unordered_map<int,bool> mp;
   vector<int> prefix(nums.size(),0);
   int count =0;
   prefix[0] = nums[0];
   for(int i=1;i<nums.size();i++){
      prefix[i] = prefix[i-1] + prefix[i];
      if(prefix[i]==target && mp[i]==false && mp[i-1]==false){
         mp[i] = true;
         count++;
      }
   }
      
}


int main(){
   vector<int> a - {-1,3,5,1,4,2,-9};
   cout<<maxNonOverlapping(a,6);

}
