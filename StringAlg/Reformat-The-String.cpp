class Solution {
// idk man i think i wrote the perfect algorithm , even worked till 90 cases. fuakkk man.
public:
        string reformat(string s) {
        if(s.size()==1){
            return s;
        }
        stack<char> c;
        stack<char> n;
        for(int i=0;i<s.size();i++){
            if(s[i]>=95 && s[i]<=121){
                c.push(s[i]);
            }
            else{
                n.push(s[i]);
            }
        }
        if(s.size()==c.size() || s.size()==n.size() ){
            return "";
        }
        string str = "";
        int turn = (c.size()<=n.size())?1:2;
        while(!c.empty() && !n.empty()){
            if(turn%2==0){
                str+= c.top(); c.pop();
                turn++;
            }
            else{
                str+= n.top(); n.pop();
                turn++;
            }
        }
        if(!c.empty()){
            str+=c.top(); c.pop();
        }
        if(!n.empty()){
            str+=n.top(); n.pop();
        }
        if(!c.empty() || !n.empty()){
            return "";
        }
        for(int i=1;i<str.size();i++){
            if((str[i-1]>=95 && str[i-1]<=121) && (str[i]>=95 && str[i]<=121)){
                return "";
            }
            else if((str[i-1]>='0' && str[i-1]<='9') && (s[i]>='0' && str[i]<='9')){
                return "";
            }
        }
        return str;
    }

};
class Solution {
// im the biggest idiot in the world , i thought 95-121 was the asci values of small a and z . im so stupid.
public:
        string reformat(string s) {
        if(s.size()==1){
            return s;
        }
        stack<char> c;
        stack<char> n;
        for(int i=0;i<s.size();i++){
            if(s[i]>=97 && s[i]<=122){
                c.push(s[i]);
            }
            else{
                n.push(s[i]);
            }
        }
        if(s.size()==c.size() || s.size()==n.size() ){
            return "";
        }
        string str = "";
        int turn = (c.size()<=n.size())?1:2;
        while(!c.empty() && !n.empty()){
            if(turn%2==0){
                str+= c.top(); c.pop();
                turn++;
            }
            else{
                str+= n.top(); n.pop();
                turn++;
            }
        }
        if(!c.empty()){
            str+=c.top(); c.pop();
        }
        if(!n.empty()){
            str+=n.top(); n.pop();
        }
        if(!c.empty() || !n.empty()){
            return "";
        }
        for(int i=1;i<str.size();i++){
            if((str[i-1]>=95 && str[i-1]<=121) && (str[i]>=95 && str[i]<=121)){
                return "";
            }
            else if((str[i-1]>='0' && str[i-1]<='9') && (s[i]>='0' && str[i]<='9')){
                return "";
            }
        }
        return str;
    }

};
