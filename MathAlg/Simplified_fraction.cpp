class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int i=1;i<n;i++){
            string frac = "";
            for(int j=i+1;j<=n;j++){
                if(__gcd(i,j)>1){continue;}
                frac += to_string(i);
                frac += "/";
                frac += to_string(j);
                ans.push_back(frac);
                frac = "";
            }
        }
        return ans;
    }
};
