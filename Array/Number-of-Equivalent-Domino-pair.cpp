class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        map<pair<int, int>, int> mp;
        
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }
            count += mp[{dominoes[i][0], dominoes[i][1]}]++;
        }

        return count;
    }
};
