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

class Solution {
// It doesnt actually get TLE, but i didnt notice one edge case, which i got from hint.
// This one passes 163/183 cases.
public:
    int getWinner(vector<int>& a, int k) {
        int win_count = 0;
        int shift = 0;
        int mx = 0;
        for(int i = 0 ; i < a.size(); i++){
            mx = max(mx, a[i]);
        }
        if(k > a.size()){
            return mx;
        }
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

class Solution {
// 183/185 , AND TLE lmao.
public:
    int getWinner(vector<int>& a, int k) {
        int win_count = 0;
        int mx = 0;
        for(int i = 0 ; i < a.size(); i++){
            mx = max(mx, a[i]);
        }
        if(k > a.size()){
            return mx;
        }
        while(win_count != k){  
            if(a[0] > a[1]){
                win_count++;
                int num = a[1];
                a.erase(a.begin()+1);
                a.push_back(num);
            }
            else{
                win_count = 1;
                int num = a[0];
                a.erase(a.begin()+0);
                a.push_back(num);
            }
        }
        return a[0];   
    }
};
