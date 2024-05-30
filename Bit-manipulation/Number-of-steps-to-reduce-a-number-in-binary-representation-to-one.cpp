class Solution {
// Naive solution is to simulate it, when we divide by 2 when a digit is even . A zero from the LSB is removed.
// when it is odd. We change the entire binary value by adding a one to it.
public:
    string add_one(string s){
         int carry = 1;
         for (int i = s.size() - 1; i >= 0; i--) {
             int dig = (s[i] - '0') + carry;
             if (dig == 2) {
                s[i] = '0';
                carry = 1;
             } else {
                s[i] = dig + '0';
                carry = 0;
                break;
             }
         }
         if(carry){
            return "1" + s; 
         }
         return s;
    }
    int numSteps(string s) {
        int count = 0;
        while(s != "1"){
            if (s.back() == '0'){
                s.pop_back();
            }
            else{
                s = add_one(s);
            }
            count++;
        }
        return count;

    }
};

class Solution {
public:
    int numSteps(string s) {
        // for the best case scenario. ex: 10000, for this res is 4.
        int count = s.size() - 1;
        int carry = 0;
        
        for(int i = s.size() - 1; i >= 1; i --){
            // for case where ex: 1011, we know that it is odd
            // so we add 1 to it. that makes it 1100. now this is even.
            // so we divide it. the divide operation costs us one count++.
            // and we hold a carry.
            if(s[i] - '0' + carry == 1){
                count++;
                carry = 1;
            }
        }
        
        return count + carry;

    }
};
