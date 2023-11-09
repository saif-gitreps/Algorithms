class Solution {
// this simple common sense solution go me 44/88 cases right lmao.
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size() % gs != 0){
            return false;
        }
        return true;
    }
};
