class Solution {
// first attempt 21/50 , lets see what the issue was

public:
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int mn = 1;
        int curr_count = 1;
        for(int i = 1; i < a.size(); i ++){
            if(a[i-1][1] >= a[i][0]){
               while(i < a.size() && a[i-1][1] >= a[i][0]){
                    i++;
               }
               curr_count++; 
            }
            else{
                curr_count++;
            }
        }
        return curr_count;    
    }
};
