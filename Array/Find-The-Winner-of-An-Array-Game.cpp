class Solution {
// Naive bruteforce, gets TLE
public:
    int getWinner(vector<int>& a, int k) {
        int win_count = 0;
        int shift = 0;
        while(win_count != k){  
            if(a[0] > a[1] && shift == 0){
                win_count++;
                int num = a[1];
                a.erase(a.begin()+1);
                a.push_back(num);
            }
            else if (a[0] < a[1] && shift == 0){
                win_count = 1;
                int num = a[0];
                a.erase(a.begin());
                a.push_back(num);
                shift = 1;
            }
            else if(a[0] < a[1] && shift == 1){
                win_count++;
                int num = a[0];
                a.erase(a.begin());
                a.push_back(num);
            }
            else if(a[0] > a[1] && shift == 1){
                int num = a[1];
                a.erase(a.begin()+1);
                a.push_back(num);
                shift = 0;
            }
        }
        return a[0];   
    }
};
