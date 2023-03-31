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
