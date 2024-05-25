class Solution {
// Idk O(n^2) was easy.
public:
    vector<int> minOperations(string a) {
        vector<int> one_index;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == '1'){
                one_index.push_back(i);
            }
        }
        vector<int> ans(a.size(), 0);
        for(int i = 0; i < a.size(); i++){
            for(auto index : one_index){
                if(a[i] == '1' && i == index){
                    continue;
                }
                ans[i] += abs(index - i);
            }
        }
        return ans;
    }
};
