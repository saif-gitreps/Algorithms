bool compare(string a, string b){
    if(a.size() == b.size()){
        return false;
    }
    else if(a.size() < b.size()){
        return true;
    }
    else{
        return false;
    }
}

class Solution {
// first attempt worked till 40/70 cases.
public:
    string arrangeWords(string text) {
        vector<string> a;
        string str = "";
        text[0] = text[0] + 32;
        for(int i = 0 ; i < text.size(); i++){
            if(text[i] == ' '){
                a.push_back(str);
                str = "";
                continue;
            }
            str += text[i];
        }
        a.push_back(str);
        sort(a.begin(), a.end(), compare);
        str = "";
        for(auto x : a){
            str += x;
            str += " ";
        }
        str.pop_back();
        str[0] = str[0] - 32;
        return str;
    }
};


// This works but the edge case is dupilcate words.

map<string,queue<int>> mp;
bool compare(string a, string b){
    if(a.size() == b.size()){
        if(mp[a].front() < mp[b].front()){
            mp[b].pop();
            return true;
        }    
        else
            return false;
    }
    if(a.size() < b.size()){
        return true;
    }
    else{
        return false;
    }
}

class Solution {
public:
    string arrangeWords(string text) {
        vector<string> a;
        string str = "";
        text[0] = text[0] + 32;
        int k = 0;
        for(int i = 0 ; i < text.size(); i++){
            if(text[i] == ' '){
                a.push_back(str);
                mp[str].push(k);
                str = "";
                k++;
                continue;
            }
            str += text[i];
        }
        a.push_back(str);
        mp[str].push(k);
        sort(a.begin(), a.end(), compare);
        str = "";
        for(auto x : a){
            str += x;
            str += " ";
        }
        str.pop_back();
        str[0] = str[0] - 32;
        return str;
    }
};
