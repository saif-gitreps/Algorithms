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
class Solution{
// idk why i coudnt come with solutions like these, 
// so here we just take the full sum till a unique balloon comes, at the same time we keep track of the max till that unique ballon.
// Then we minus the max from the sum and just count += it.
    int minCost(string s, vector<int>& cost) {
        int res = 0, max_cost = 0, sum_cost = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] != s[i - 1]) {
                res += sum_cost - max_cost;
                sum_cost = max_cost = 0;
            }
            sum_cost += cost[i];
            max_cost = max(max_cost, cost[i]);
        }
        res += sum_cost - max_cost;
        return res;
    }
};
