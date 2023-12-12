class Solution {
// After dubuggin it a little, it worked 100%, but the topic shows it was a dp problem.
public:
    int minCost(string a, vector<int>& neededTime) {
        int count = 0;
        for(int i = 1; i < a.size(); i++){
            if(a[i-1] == a[i]){
                priority_queue<int> pq;
                while(i < a.size() && a[i-1] == a[i]){
                    pq.push(-neededTime[i-1]);
                    i++;
                }
                pq.push(-neededTime[i-1]);
                while(pq.size() != 1){
                    count += abs(pq.top());
                    pq.pop();
                }
            }
        }
        return count;  
    }
};
