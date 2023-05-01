class Solution {
public:
    string reverseWords(string s) {
        string newWord = "";
        string word = "";
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                word += s[i];
                if(i+1<s.size() && s[i+1]==' '){
                    st.push(word);
                }
                else if(i+1==s.size()){
                    st.push(word);
                }
            }
            else{
                word = "";
            }
        }
        while(!st.empty()){
            newWord += st.top();
            newWord += " ";
            st.pop();
        }
        int n = newWord.size()-1;
        newWord.erase(newWord.begin()+n,newWord.end());
        return newWord;
    }
};
