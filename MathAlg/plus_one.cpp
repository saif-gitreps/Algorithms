class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int n = a.size();
        for(int i = n-1; i>=0; i-- ){
            if(i==n-1){
                a[i]++;
            }
            if(a[i]==10){
                a[i] = 0;
                if(i!=0){
                    a[i-1]++;
                }
                else{
                  // if this condition activates that means all the numbers are 9 and therefore we will have a 0 at the end anyway.
                    a.push_back(0);
                    a[i] = 1;
                }
            }
        }
    return a;}
};

class Solution {
public:
    // logically better solution.
    vector<int> plusOne(vector<int>& a) {
        int n = a.size();
        for(int i = n-1; i>=0; i-- ){
            if(a[i]==9){
                a[i] = 0;
            }
            else{
                a[i]++;
                return a;
            }
        }
        a.push_back(0);
        a[0] = 1;
        return a;
        }
};


class Solution {
// now this solution can work for all cases of adding any digits to one's place
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; i--) {
            digits[i] += carry;
            carry = (digits[i] + carry) % 10;
            if (digits[i] <= 9) {
                carry = 0;
                break;
            } else {
                digits[i] = digits[i] % carry;
            }
        }

        if (carry) {
            reverse(digits.begin(), digits.end());
            digits.push_back(carry);
            reverse(digits.begin(), digits.end());
        }

        return digits;
    }
};
