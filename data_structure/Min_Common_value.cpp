class Solution {
  // leetcode 2540
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int mn = INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]>0){
                mn = min(mn,nums2[i]);
            }
        }
        if(mn==INT_MAX){
            return -1;
        }
        else{
            return mn;
        }
        
    }
};
