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

class Solution {
// great ! shows TLE NOW!
public:
    int partition(vector<int> &a,int left,int right){
    int l = left;
    int r = right;

    // a[l] is our pivot.

    while( l < r){
        if(a[l+1]  <= a[l]){
            swap(a[l+1] , a[l]);
            l++;
        }
        else if(a[r] > a[l]){
            r--;
        }
        else{
            // this condition is triggered when
            // a[l + 1] is greater than pivot 
            // and a[r] is smaller than pivot. 
            swap(a[r] , a[l + 1 ]);
        }
    }
    return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int index = partition(nums,0,nums.size()-1);
        while(true){
            if((nums.size() - index) == k) {
                return nums[index];
            }
            else if((nums.size() - index) < k){
                index = partition(nums,0,index-1);
            }
            else{
                index = partition(nums,index+1,nums.size()-1);
            }
        }
        return -1;
    }
};

