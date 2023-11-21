class Solution {
// I tried to figure out something , it didnt work at all.
public:
    long long numberOfWeeks(vector<int>& a) {
        sort(a.begin() , a.end());
        long long sum = 0;
        for(auto s: a){
            sum += s;
        }
        vector<long long> mp(sum+1,0);
        for(int i = 1 ; i < a.size(); i++){
            sum += a[i];
            int diff = a[i] - a[i-1];
            mp[diff] = 1;
        }
        int limit = sum;
        for(int i = 1 ; i <= limit; i++){
            if(mp[i] == 0){
                sum--;
            }
        }
        return sum;
    }
};
