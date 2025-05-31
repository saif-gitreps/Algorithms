class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            // find the position of '#'
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i)); // length before '#'
            result.push_back(s.substr(j + 1, len)); // actual string
            i = j + 1 + len;
        }
        return result;
    }
};
