class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> mp(26,0);
        for(int i = 0 ; i < s.size();i ++){
            mp[s[i]-'a'] = i;
        }
        int start =0 ; int end = 0;
        for (int i = 0 ; i < s.size(); i++){
            end = max(end,mp[s[i] - 'a']);
            if(i == end){
                ans.push_back( i - start + 1);
                start  = i + 1;
            }
        }
        return ans;
    }

};
