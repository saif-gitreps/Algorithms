class Solution {
public:
    bool isValid(string s) {
        stack<char> stacc;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                stacc.push(s[i]);
                continue;
            }
            else{
                if(!stacc.empty()){
                    if( (s[i]==')' && stacc.top()=='(')
                     || (s[i]=='}' && stacc.top()=='{')
                     || (s[i]==']' && stacc.top()=='[') ){
                         stacc.pop();
                     }
                     else{
                         return false;
                     }
                }
                else{
                    return false;
                }
            }
        }
        return (stacc.empty())? true:false;
    }
};
