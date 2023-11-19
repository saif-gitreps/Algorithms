class Solution {
// first attempt 60/78 cases passed.
public:
    int furthestBuilding(vector<int>& h, int b, int lad) {
        int ans = 0;
        for(int i = 1 ; i < h.size(); i++){
            if(b <= 0 && lad <= 0){
                if(h[i-1] > h[i]){
                    ans++;
                    continue;
                }
                else{
                    break;
                }                
            }
            if(h[i-1] > h[i]){
                ans++;
            }
            else{
                if(b >= abs(h[i-1]-h[i])){
                    b -= abs(h[i-1]-h[i]);
                    ans++;
                }
                else if(lad >= 1){
                    lad--;
                    ans++;
                }
            }
        }
        return ans;
    }
};


class Solution {
/*
understood this one , our basic idea is we keep on using bricks , now if we run out of bricks,
we will take the largest difference, and then take back that difference and put it back in our brick value
, why is that ? because the largest difference in the pq tells that we used that much brick, now lets take our brick back
and use a ladder instead, we got no ladder ? that means we are stuck , so we will print the current index.
*/
public:
    int furthestBuilding(vector<int>& h, int b, int lad) {
        priority_queue<int> pq; 
        for(int i = 0; i+1 < h.size();i ++){
            int diff = h[i+1] - h[i];
            if(diff > 0){
                b -= diff;
                pq.push(diff);
                if(b < 0){
                    if(lad <= 0){
                        return i;
                    }
                    int take_back = pq.top();
                    pq.pop();
                    b += take_back;
                    lad--;
                }
            }
        }
        return h.size()-1;
    }
};
