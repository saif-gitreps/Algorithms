class Solution {
// topic is enumeration but popular solutions are different topic.
// when hint said to use recursion , i used that. using recusion over 9 digits is not alot.
// i put it in sliding window because i a sliding window technique that made more sense.
public:
    vector<int> ans;
    void kev(int i, string str, string &s, int low, int high){
        if(i == s.size()){
            int num = 0;
            int prev = str[0];
            for(int j = 0; j < str.size(); j++){
                if(str[j] - prev > 1){
                    return;
                }
                prev = str[j];
                num = num * 10 + str[j] - '0';
            }
            if(num >= low && num <= high){
                ans.push_back(num);
            }
            return;
        }
        str += s[i];
        kev(i + 1, str, s, low, high);
        str.pop_back();
        kev(i + 1, str, s, low, high);
    }
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        kev(0, "", s, low , high);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
// i this making j = 0 and j < i also will work.
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> nums, ans;
        for (int i = 0; i < s.size(); i++) {
            string x = "";
            for (int j = i; j < s.size(); j++) {
                x += s[j];
                int num = stoi(x);
                if (low <= num && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
// by recursion i think the hint meant this solution. SC and TC is close to O(1).

public:
    vector<int> ans;
    
    void dfs(int low, int high, int i, int num){
        
        if (num >= low and num <= high)
            ans.push_back(num);
    
        if (num > high or i>9) 
            return;
        dfs(low, high, i+1, num*10 + i);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1; i<=9; i++)
            dfs(low, high, i, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
