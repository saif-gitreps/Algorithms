class Solution {
// This was indeed a difficult problem.
// I sort of understood but was wrong at the same time.
// In this intuition we place the cards from ASC and we skip
// places in ans array. ex, 12345678 -> 1_2_3_4_
// if we find an empty place. We first will place it, then enable skip.
// When we find another empty place and skip is enable, We literally skip it. Then disable skip.
// On the next encounter of an empty place, we place (now that skip is disabled).
// This intuition was not at all similar to the simulation in the problem.
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n, 0);
        sort(deck.begin(), deck.end());


        int i = 0,j = 0, skip = 0;
        while(i < n){
            if(ans[j] == 0) {
                if(!skip) {
                    ans[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }
            j = (j + 1) % n;
        }

        return ans;
    }
};
