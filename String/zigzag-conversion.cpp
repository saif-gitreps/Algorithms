class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        vector<vector<char>> temp(numRows);

        int i = 0;
        int j = 0;
        int z = 0;
        int state = 0;

        while (i < s.size()) {
  
            if (state == 0) {  
                temp[z].push_back(s[i]);
                z++;
                if (z == numRows) { 
                    state = 1;
                    z = numRows - 2;
                }
            } else if (state == 1) { 
                temp[z].push_back(s[i]);
                z--;
                if (z == -1) { 
                    state = 0;
                    z = 1;
                }
            }

            i++;
        }

        string result;
        for (int i = 0; i < numRows; i++) {
            for (char c : temp[i]) {
                result += c;
            }
        }

        return result;
    }
};
