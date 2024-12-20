class Solution {
// bruteforce
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;

        for (int i = 0; i < prices.size(); i++) {
           bool found = false;
           for (int j = i + 1; j < prices.size(); j++) {
                if (prices[i] >= prices[j]) {
                    ans.push_back(prices[i] - prices[j]);
                    found = true;
                    break;
                }
           }

           if (!found) ans.push_back(prices[i]);
        } 

        return ans;
    }
};

class Solution {
// monotonic sol, just dry run this [8,4,6,2,3], the key thing i understood is that,
// when we are at a min index, we will look past all the greater elements (which are in the stack) and minus them.
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            
            st.push(i);
        }

        return prices;
    }
};
