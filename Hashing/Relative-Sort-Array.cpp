class Solution {
// i did sort it and hash and i still got an error at test case 17.
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < arr1.size(); i++){
            mp[arr1[i]]++;
        } 
        vector<int> ans; 
        for(int i = 0 ; i < arr2.size();i ++ ){
            while(mp.count(arr2[i]) && mp[arr2[i]] != 0){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        sort(arr1.begin(),arr1.end());
        for(auto x : mp){
            if(x.second!=0){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};


class Solution {
//not best in terms of memeory and space but best i could come up with all these stress

public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(int i = 0 ; i < arr1.size(); i++){
            mp[arr1[i]]++;
        } 
        vector<int> ans; 
        for(int i = 0 ; i < arr2.size();i ++ ){
            while(mp.count(arr2[i]) && mp[arr2[i]] > 0){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for(auto x : mp){
            if(x.second>0){
                int n = x.second;
                while(n--){
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
    }
};
