class Solution {
public:
  // o(n^2) soln, shows TLE 
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> a;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    //if(i!=j && i!=k && j!=k){
                        if(nums[i]+nums[j]+nums[k]==0){
                            a.insert({nums[i],nums[j],nums[k]});
                        }
                    //}
                }
            }
        }
        vector<vector<int>> ans;
        for( auto s : a){
            ans.push_back(s);
        }
    return ans;
        
    }
};

//first attempt :1 
// mistake was i forgot to add j++;k-- after the condition was fullfilled.
// mistake two , had to start j at i+1 instead of 0 per loop.
// mistake three, had to keep j<k becaue we dont want the same variable number.
vector<vector<int>> threeSum(vector<int>& nums){
   set<vector<int>> a;
   vector<vector<int>> newarr;
   sort(nums.begin(),nums.end());
   int i=0,j=0,k=0;
   while(i<nums.size()){
      j=0; k = nums.size()-1;
      while(j<=k){
         if(nums[i]+nums[j]+nums[k]==0){
            a.insert({nums[i],nums[j],nums[k]});
         }
         else if(nums[i]+nums[j]+nums[k]<0){
            j++;
         }
         else{
            k--;
         }
      }
      i++;
   }
   for(auto s: a){
      newarr.push_back(s);
   }
   return newarr;
}
