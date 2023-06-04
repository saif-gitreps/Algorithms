class Solution {
    // attempt 1 : passed test case 1.
    // i dont know why it is showing bug for second test case.
    // it also worked till 21 test cases, the second test case was hindering it.
public:
    void rev(int i,vector<int> a,set<vector<int>>& final_ds,vector<int>& ds,int sum,int target){
        if(i==a.size()){
            if(sum==target){
                sort(ds.begin(),ds.end());
                final_ds.insert(ds);
                return;
            }
            return;
        }
        sum += a[i];
        ds.push_back(a[i]);
        rev(i+1,a,final_ds,ds,sum,target);
        sum -= a[i];
        ds.pop_back();
        rev(i+1,a,final_ds,ds,sum,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> final_ds;
        vector<vector<int>> finally;
        vector<int> ds;
        map<int,int> mp;
        rev(0,candidates,final_ds,ds,0,target);
        for(auto s : candidates){
            mp[s]++;
        }
        for(auto s: final_ds){
            int i =0;
            for(;i<s.size();i++){
               int temp = mp[s[i]]; 
                if(temp>=1){
                    temp--;
                }
                else{
                  break;
                }
            }
            if(i==s.size()){
                    finally.push_back(s);
                }
        }
        return finally;
    }
};