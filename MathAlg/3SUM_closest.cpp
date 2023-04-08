class Solution {
  // first raw attempt , didnt work.
public:
    int threeSumClosest(vector<int>& nums, int target) {
       vector<int> a;
       set<int> s;
       int i=0,j=0,k=0;
       while(i<nums.size()){
          j= i+1; k = nums.size()-1;
          while(j<k){
             s.insert(nums[i]+nums[j]+nums[k]);
             j++;
             k--;
          }
          i++;
       }
       int mn=-1001,mx=1001;
       for(auto num: s){
          if(num<target){
             mn = max(num,mn);
          }
          else if(num>target){
             mx = min(num,mx);
          }
       }
      return (abs(mn-target)<abs(mx-target))? mn:mx;
    }
};

// remake of the solution , works for 77 test cases/ 99.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       vector<int> a;
       set<int> s;
       int i=0,j=0,k=0;
       sort(nums.begin(),nums.end());
       while(i<nums.size()){
          j= i+1; k = nums.size()-1;
          while(j<k){
            s.insert(nums[i]+nums[j]+nums[k]);
             if((nums[i]+nums[j]+nums[k])<target){
               j++;
             }
             else if((nums[i]+nums[j]+nums[k])>target){
               k--;
             }
             else{
                j++;
                k--;
             }
               
          }
          i++;
       }
       int mn=-1001,mx=1001;
       for(auto num: s){
          if(s.size()==1){
             return num;
          }
          if(num<target){
             mn = max(num,mn);
          }
          else if(num>target){
             mx = min(num,mx);
          }
       }
      return (abs(mn-target)<abs(mx-target))? mn:mx;
    }
};
