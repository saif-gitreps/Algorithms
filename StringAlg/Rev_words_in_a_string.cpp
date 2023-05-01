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

class Solution {
public:

    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
    
    void reverseWords(string &s) {
        
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;
            
        }
        
        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }
};
