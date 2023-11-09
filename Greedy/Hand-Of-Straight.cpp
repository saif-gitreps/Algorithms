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

class Solution {
/*
    the actual intuition is we hash all the values and then we keep a continuous pointer 
    to the smallest element. Ones we decide a pointer. we know we have to check Pointer_val + Group-Size - 1.
    Becaue lets say how do we know if we got [1,2,3] where our GS is 3. we take 1 + 3 - 1. one is our smallest pointer value
    3 is the group we need to create. Now we can iterate and check if the consecutive value exist or no, if it doesnt we return a fallse
    else we decrement it, and once the value gets to 0 , we erase is completely.
*/
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size() % gs != 0){
            return false;
        }
        if(gs == 1){
            return true;
        }
        map<int,int> mp;
        for(int i = 0; i < hand.size(); i++){
            mp[hand[i]] ++;
        }
        while(mp.size() > 0){
            int begin_num = mp.begin()->first;
            int group_len = begin_num + gs -1;
            for(int i = begin_num; i <= group_len; i++){
                if(mp.count(i) == 0){
                    return false;
                }
                else if(mp[i]-1 == 0){
                    mp.erase(i);
                }
                else{
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
