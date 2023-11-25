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

//LMAOOOOOOOOOOOOOOOOOOOOOOO
//So I kept my comparator to compare end intervals of each interval and it worked.
//default was a[0] < b[0]. (why default? because it is giving the same result as before using a comparator).
//apparently it was a[1] < b[1]
// TC nlog n.
bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), compare);
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
