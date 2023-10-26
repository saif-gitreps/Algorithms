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

class Solution {
// another solution, works till 24/50. 
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int count = a.size();
        for(int i = 1; i < a.size(); i ++){
            if(a[i-1][1] >= a[i][0]){
               int start_point = a[i-1][1];
               while(i < a.size() && start_point >= a[i][0]){
                    i++;
                    count--;
               }
            //    i++;
            }
        }
        return count;    
    }
};

class Solution {
// my intuition was also right , i guess some dots just dont click the way you wanted to.
public:
    static bool comparator(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), comparator);
        int count = 1;
        int start_point = a[0][1];
        for(int i = 1; i < a.size(); i ++){
            if(start_point < a[i][0]){
                count++;
                start_point = a[i][1];
            }
        }
        return count;    
    }
};
