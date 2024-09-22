class Solution {
// i mean it wokred, tho the worst solution.
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        for (int i = 0; i < queries.size(); i++) {
            sort(queries[i].begin(), queries[i].end());
        }

        for (int i = 0; i < words.size(); i++) {
            sort(words[i].begin(), words[i].end());
        }

        multiset<int> st;

        for (auto word: words) {
            char a = word[0];
            int count = 1;

            for (int j = 1; j < word.size(); j++) {
                if (word[j] == a) count++;
                else break;
            }
            
            st.insert(count);
        }

        // for (auto it : st) {
        //     debug(it);
        // }

        // debug("-------------------");

        vector<int> ans;

        for (auto word: queries) {
            char a = word[0];
            int count = 1;

            for (int j = 1; j < word.size(); j++) {
                if (word[j] == a) count++;
                else break;
            }

            auto it = st.upper_bound(count);

            // debug(*it);

            // if (*it <= count) ++it; 

            // debug(*it);


            int numberOfWords = (words.size() - distance(st.begin(), it));

            // debug(words.size() - numberOfWords);

            ans.push_back(numberOfWords);
        }

        return ans;
    }
};
