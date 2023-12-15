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
