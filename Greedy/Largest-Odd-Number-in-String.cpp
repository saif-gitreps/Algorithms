// dont know whats the issue with this, the comparison was supposed to work but it doesnt.
string largestOddNumber(string num) {
      string mx = "";
      for (int i = 0; i < num.size(); i++) {
          string number = "";
          for(int j = i; j < num.size(); j++) {
              number += num[j];
              debug(mx);
              if ((number.back() - '0') % 2 == 1 && number > mx) {
                  mx = number;
              }
          }
          debug(mx);
      }

      return mx;
  }

class Solution {
// I did get one thing right whcih was to only check the last digit, but one key thing i missed is
// we could just loop from behind, instead of creating a 2 pointer substr method. because we know only the last 
// digit matters.
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - 1; i >= 0; i --) {
            if ((num[i] - '0' ) % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};
