class Solution {
public://
    string oddString(vector<string>& words) {
        map<vector<int>,int> m;
        vector<vector<int>> a;
        vector<int> b;
        for(int i =0;i<words.size();i++){
            string temp = words[i];
            for(int j=1;j<words[i].size();j++){
                int num = temp[j]-temp[j-1];
                b.push_back(num);
            }
            a.push_back(b);
            m[b]++;
        }
        
        for(int i=0;i<a.size();i++){
            if(m[a[i]]==1){
                return words[i];
            }
        }
        return "no";
    }
};


class Solution2 {
    // this solution worked.
public:
        string oddString(vector<string>& words) {
        map<vector<int>,int> m;
        vector<vector<int>> a;
        for(int i =0;i<words.size();i++){
            string temp = words[i];
            vector<int> b;
            for(int j=1;j<words[i].size();j++){
                int num = temp[j]-temp[j-1];
                b.push_back(num);
            }
            a.push_back(b);
            m[b]++;
        }
        
        for(int i=0;i<a.size();i++){
            if(m[a[i]]==1){
                return words[i];
            }
        }
        return "no";
    }
};
