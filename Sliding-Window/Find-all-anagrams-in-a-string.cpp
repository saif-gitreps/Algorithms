class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if(s.size() < p.size()){
            return ans;
        }

        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);

        for(int i = 0 ; i < p.size(); i++){
            mp1[p[i] - 'a']++;
            mp2[s[i] - 'a']++;
        }    

        if(mp1 == mp2){
            ans.push_back(0);
        }

        for(int i = p.size() ; i < s.size(); i++){
            mp2[s[i - p.size()] - 'a']--;
            mp2[s[i]  - 'a']++;

            if(mp1 == mp2){
                ans.push_back(i - p.size() + 1);
            }
        }

        return ans;
    }
};
