class Solution {
  // test case passes 185/211
public:
    int maxDiff(int n) {
        string num = to_string(n);
        int mx = -1;
        for(int i=0;i<num.size();i++){
            string num2 = num;
            replace(num2.begin(),num2.end(),num2[i],'9');
            for(int j =0;j<num.size();j++){
                string num3 = num;
                replace(num3.begin(),num3.end(),num3[j],'1');
                int n1 = stoi(num2);
                int n2 = stoi(num3);
                int res = n1 - n2;
                mx = max(mx,res);
            }
        }
        return mx;
    }
};

class Solution {
  // damn i cant believe i solved it. 
public:
    int maxDiff(int n) {
        string num = to_string(n);
        int mx = -1;
        for(int i=0;i<num.size();i++){
            string num2 = num;
            replace(num2.begin(),num2.end(),num2[i],'9');
            for(int j =0;j<num.size();j++){
                string num3 = num;
                if(j>0 && num3[0]!=num[j]){
                    replace(num3.begin(),num3.end(),num3[j],'0');    
                }
                else {
                    replace(num3.begin(),num3.end(),num3[j],'1');
                }
                int n1 = stoi(num2);
                int n2 = stoi(num3);
                int res = n1 - n2;
                mx = max(mx,res);
            }
        }
        return mx;
    }
};

class Solution {
  //best solution.
public:
    int maxDiff(int num) {
        return getMax(num) - getMin(num);
    }

    int getMax(int num) {
        string s = to_string(num);
        char ch = s[0];
        for (const auto& c: s) {
            if (c != '9') {
                ch = c;
                break;
            }
        }
        int ans = 0;
        for (const auto& c: s) {
            ans = ans * 10 + (c == ch ? 9 : (c-'0'));
        }

        return ans;
    }

    int getMin(int num) {
        string s = to_string(num);
        char ch = s[0];
        if (ch == '1') {
            for (int i = 1; i < s.size(); i++) {
                char c = s[i];
                if (c != '0' && c != '1') {
                    ch = c;
                    break;
                }
            }
        }
        int ans = 0;
        for (const auto& c: s) {
            ans = ans * 10 + (c == ch
                ? ch == s[0]
                    ? 1
                    : 0
                : (c-'0'));
        }

        return ans;
    }
};
