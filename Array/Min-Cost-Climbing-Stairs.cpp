class Solution {
// this aint easy problem yo , its a hard problem , also passed till 149/280 cases
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if( cost.size() <= 2){
            return min( cost[0], cost[1]);
        }
        int sum = 0,i;
        for(i = 2 ; i < cost.size() ; ){
            if(i == cost.size() - 1 ){
                if(cost[i-1] < ( cost[i - 2] + cost[i]) ){
                    sum += cost[i - 1];
                    i += 2;
                }   
                else{
                    sum += cost[i];
                    sum += cost[i-2];
                    i += 1;
                }
                break;
            }
            if(cost[i-1] < ( cost[i - 2] + cost[i]) ){
                sum += cost[i - 1];
                i += 2;
            }
            else if(cost[i-1] >= ( cost[i - 2] + cost[i])){
                sum += cost[i - 2];
                i += 1;
            }
        }
        return sum;
    }
};
