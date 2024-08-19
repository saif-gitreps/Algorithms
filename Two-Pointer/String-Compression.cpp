class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> temp;
        for (int i = 0; i < chars.size(); i++) {
            int ptr = i;
            int char_count = 1;
            while (i + 1 < chars.size() && chars[i] == chars[i + 1]) {
                i++;
                char_count++;
            }

            if (char_count == 1) {
                temp.push_back(chars[ptr]);
            } else {
                string str = to_string(char_count);
                temp.push_back(chars[ptr]);
                for (int k = 0; k < str.size(); k++) 
                    temp.push_back(str[k]);
            }
        }

        chars = temp;
        return temp.size();
    }
};
