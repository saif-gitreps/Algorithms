class Solution {
public:
  // best soln
    int findTheLongestBalancedSubstring(string s) {
        string temp = "01";
        int count = 0;
        while(temp.size()<=s.size()){
            if(s.find(temp)!=string::npos){
                count = temp.size();
            }
            temp = '0'+temp+'1';
        }
        return count;
    }
};

class Solution {
  // soln that was my original idea.
public:
    int findTheLongestBalancedSubstring(string str) {
        
        
        int res = 0;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0;  i< str.length(); ++i) {
            
            int val = str[i] - '0';
            if (val == 0) {
                if (cnt1 == 0)
                    ++cnt0;
                else {
                    cnt0 = 1;
                    cnt1 = 0;
                }
            } else {
                ++cnt1;
            }
            res = max(res, 2*min(cnt0, cnt1));
        }
        return res;
    }
};
