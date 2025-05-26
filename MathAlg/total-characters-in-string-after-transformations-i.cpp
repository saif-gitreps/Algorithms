class Solution {
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        while (t--) {
            string temp = "";
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 'z') {
                    temp += "ab";
                } else {
                    temp += (s[i] + 1);
                }
            }
            s = temp;
        }

        return s.size() % mod;
    }   
};

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // we are trying to simulate the above brutforce attempt but with a string map.
        int count = 0;
        int const mod = 1e9 + 7;
        int nums[26] = {0};

        for (char ch : s) {
            nums[ch - 'a']++;
        }

        while (t--) {
            int current_word[26] = {0};

            for (int j = 0; j < 26; j++) {
                if (j == 25 && nums[j] > 0) {
                    current_word[0] = (current_word[0] + nums[j]) % mod;
                    current_word[1] = (current_word[1] + nums[j]) % mod;

                    // why nums[j]/'z' ? because initially, for every z, we get an 'a' and 'b'. so the number of 'ab' increases.
                } else if (j < 25) {
                    current_word[j + 1] = (current_word[j + 1] + nums[j]) % mod;

                    // if you have 'aaa', all of the 'a's will turn in to 'bbb'. so increase the freq of the next letter with the freq of current letter.
                }
            }

            for (int j = 0; j < 26; j++) {
                nums[j] = current_word[j];
            }
        }

        for (int i = 0; i < 26; i++) {
            count = (count + nums[i]) % mod;
        }

        return count;
    }
};
