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

class Solution {
    // attemp 2 : worked till 23 test cases then my memory limited exceeded.
public:
    void rev(int i,vector<int> a,set<vector<int>>& final_ds,vector<int>& ds,int sum,int target){
        if(i==a.size()){
            if(sum==target){
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
        sort(candidates.begin(),candidates.end());
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

class Solution {
    // attempt 3: worked till 23 test case , this one is more intuitive and easily implmented.
    // but it shows MLE.
public:
    set<vector<int>> s;
    void rev(int i,int sum,vector<int> &ds,vector<int> a){
         if(i==a.size()){ 
           if(sum==0){
               s.insert(ds);
               return;
           }
           return;
        }
        if(sum>=a[i]){
            ds.push_back(a[i]);
            rev(i+1,sum-a[i],ds,a);
            ds.pop_back();
        }
        rev(i+1,sum,ds,a);
    } 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> final_ds;
        vector<int> ds;
        rev(0,target,ds,candidates);
        for(auto x: s){
            final_ds.push_back(x);
        }
        return final_ds;
    }
};

