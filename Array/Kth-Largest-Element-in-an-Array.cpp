class Solution {
public:
// lets get the obvious solution out of the way.
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size() - k];   
    }
};

class Solution {
// another obvious solution but with priority queue.
// space - O(n).
// time - O(N log (N))
// also forgot deleting or poping from pq is also O(log n) {since its a heap tree}.
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i =0  ; i < nums.size(); i++){
            pq.push(nums[i]); //  log(n) insertion.
        } 
        int i = 1;
        while(pq.empty() == false){
            // this is worst case O(n).
            // best case O(1) or O(long) or O(sqrt(n)).
            if(i == k){
                return pq.top();
            }
            i++;
            pq.pop();
        }
        return -1;
    }
};

