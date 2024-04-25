class Solution {
/*  
  The missing intuition I had was that I had to start from right and keep a monotonic Decreasing stack.
  What I instead tried was starting from left,
  iterating from right, and keep a mono dec stack will always keep the next greater ele of nums[i] on top of the
  stack.
  now for the case of circular, all we could have just done is 
  Gone around a circle one more time and the edge case was solved.
*/
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = (n * 2) - 1; i >= 0; i --){
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if(!st.empty()){
                ans[i % n] = st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
