class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //Correctly guessed we had to use Priority queue.
        priority_queue<pair<int,char>> pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        //Correctly guessed till this much.
        int i = 0;
        string str = "";
        while(true){
            if(i >= 1){
                if(str[i-1] == str[i] && pq.top().second == str[i]){
                    pair<int,int> pick = pq.top();
                    pq.pop();
                    pair<int,int> temp = pq.top();
                    str += temp.second;
                    i++;
                    int val = temp.first-1;
                    temp = {val, temp.second};
                    pq.push(temp); pq.push(pick);
                }
                if(str[i-1] == str[i]){
                    break;
                }
            }
            else if(i < 2){
                pair<int,int> temp = pq.top();
                str += temp.second;
                i++;
                int val = temp.first-1;
                temp = {val, temp.second};
                pq.push(temp);
            } 
        }
        return str;
    }
};
