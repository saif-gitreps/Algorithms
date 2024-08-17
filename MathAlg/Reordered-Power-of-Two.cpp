class Solution {
/*
  sort the first string
  find the power of 2 that is less than and equal to 10^9
  put those powers into a string array and sort each of them
  then find the power of two that matches string s.
*/
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        vector<string> powers;

        for (int i = 0; i <= 30; i++) {
            int p = pow(2, i);
            powers.push_back(to_string(p));
        }

        for (int i = 0; i <= 30; i++)
            sort(powers[i].begin(), powers[i].end());

        for (int i = 0; i <= 30; i++) { 
            if (powers[i] == s) {
                return true;
            }
        }

        return false;
    }
};
