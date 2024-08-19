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


class Solution {
// try to simulate it with "aaabbbbccc"
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int writeIndex = 0;  // Index where we'll write the compressed character
        int i = 0;  // Index to iterate through chars
        
        while (i < n) {
            char currentChar = chars[i];
            int charCount = 0;
            
            // Count occurrences of the current character
            while (i < n && chars[i] == currentChar) {
                i++;
                charCount++;
            }
            
            // Write the character
            chars[writeIndex++] = currentChar;
            
            // If the character appears more than once, write the count
            if (charCount > 1) {
                string countStr = to_string(charCount);
                for (char c : countStr) {
                    chars[writeIndex++] = c;
                }
            }
        }
        
        // The length of the compressed array
        return writeIndex;
    }
};
