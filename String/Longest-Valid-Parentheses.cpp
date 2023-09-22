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
