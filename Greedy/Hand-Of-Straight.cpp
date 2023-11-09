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


class Solution {
// a good attempt u could say , but still failed. 73/84 casese passed.
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size() % gs != 0){
            return false;
        }
        if(gs == 1){
            return true;
        }
        sort(hand.begin(), hand.end());
        int count = 0;
        int temp_count = 1;
        for(int i = 1; i <= hand.size(); i++){
            if(temp_count == gs){
                count ++;
                temp_count = 1;
                continue;
            }
            if(abs(hand[i-1]-hand[i]) >= 2){
                return false;
            }
            else{
                temp_count++;
            }
        }
        return true;
    }
};
