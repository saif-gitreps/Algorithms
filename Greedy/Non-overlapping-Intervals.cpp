class Solution {
// Attempted worked till only 19 cases.
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int count = 0;
        for(int i = 1; i < a.size(); i++){
            if (a[i-1][0] == a[i][0] && a[i-1][1] == a[i][1]) {
                count++;
            }
            else if(a[i-1][1] > a[i][0]){
                int temp = a[i-1][1];
                while(i < a.size() && temp > a[i][0]){
                    i++;
                    count++;
                }
            }
        } 
        return count;
    }
};
