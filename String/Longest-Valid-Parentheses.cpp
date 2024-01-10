class Solution {
//worked till 156/231 . first attempt.
public:
    int longestValidParentheses(string a) {
        stack<char> s;
        int mx = 0;
        string sub = "";
        bool on = false;
        for(int i = 0 ; i < a.size() ; i ++ ){
            if(a[i] == '('){
                s.push(a[i]);
            }
            if(a[i] == ')'){
                if(s.empty()==false){
                    sub += a[i];
                    sub += s.top();
                    s.pop();
                    on = true;
                }
                else{
                    sub = "";
                }
            }
            int n = sub.size();
            mx = max(n,mx);
        }
        return mx;
    }
};

class Solution {
// remember left_count > 0 means there can be atleast minimum mx length of 2 , or one valid paren.
// i need to practically think better, 
// here i - d[i] is check condition for 
// 1) lets say () () , lets focus on the 3rd index, on 3rd index, dp[i] is 2 because we found one valid parent.
// Now , we have to go back 2 value behind to check if we found another valid paren that is consecutive to this one.
// why dp[i-1] + dp[i]; this condition is for conditions like (()) , lets say the last index here, dp[i- 1] will help us to calculate ,
// along with max of the previous , like (( )<- at his index, max is 2, ) <- at this index , its is 2 + , value of the previous which is 2, so 2 + 2 = 4 is mx.
 public:
    int longestValidParentheses(string a) {
        vector<int> dp(a.size(), 0);
        int left_count = 0;
        int mx = 0;
        for(int i = 0 ; i < a.size(); i ++){
            if(a[i] == '('){
                left_count++;
            }
            else{
                if(left_count > 0){
                    dp[i] = dp[i - 1] + 2;
                    dp[i] += (i - dp[i] >= 0) ? dp[i - dp[i]] : 0;
                    mx = max(dp[i], mx);
                    left_count--;
                }
            }
        }
        return mx;
    }
};
