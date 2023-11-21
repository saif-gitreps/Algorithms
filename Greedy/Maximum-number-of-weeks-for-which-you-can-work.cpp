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


class Solution {
public:
    long long numberOfWeeks(vector<int>& a) {
        // I knew there was a trick to this, but i could not figure it out.
        // The intuition is We take the max, if the max is greater than sum of rest(excluding the max element) of the elements.
        // Then we use the formula rest * 2 + 1
        // else we print the minimum of those those.

        long long sum =0;
        long long mx = 0;
        for(int i = 0 ;i < a.size(); i++){
            sum += a[i];
            mx = max(mx, (long long)a[i]);
        }
        long long remaining_sum = sum - mx;
        return min((remaining_sum * 2 + 1), sum);
    }
};
