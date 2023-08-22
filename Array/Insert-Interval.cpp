class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& new_interval) {
        vector<vector<int>> ans;
        int i = 0; int n = a.size();
        
        //this is the loop before finding the interval,push everything.
        
        while (i < n && a[i][1] < new_interval[0]){
            //this while loop will only stop if there is an interval between.
            ans.push_back(a[i++]);
        }
        
        // mI stands for merged Interval, the thing that is gonna get merged inside the new array.

        vector<int> mI = new_interval;
        
        // getting the merged interval if any.
        
        while (i < n && a[i][0] <= new_interval[1]){
            mI[0] = min(mI[0],a[i][0]);
            mI[1] = max(mI[1],a[i][1]);
            i++;
        }
        
        //this is the loop to get everything after getting the new interval.
        ans.push_back(mI);
        
        while(i < n){
            ans.push_back(a[i++]);
        }
        
        return ans;
    }
};
