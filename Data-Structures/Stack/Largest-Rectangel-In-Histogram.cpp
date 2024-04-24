class Solution {
// Naive bruteforce, TLE 
public:
    int largestRectangleArea(vector<int>& h) {
        int mx = 0;
        for(int i = 0 ; i < h.size(); i++){
            int left = i - 1;
            int right = i + 1;
            while(left >= 0 && h[left] >= h[i]){
                left--;
            }
            while(right < h.size() && h[right] >= h[i]){
                right++;
            }
            left++;
            right--;
            int height = (right - left + 1) * h[i];
            mx = max(height, mx);
        }
        return mx;
    }
};

/*
    better solution, O(n) technically O(3n).
    we will keep two array, the right boundary and the left boundary.
    we will use a monotonic stack for this.
    both right and left array will calculate the boundary for each element in the array Height.

    need to watch over and over again to understand this problem.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        vector<int> left(n, 0), right(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }

            if(st.empty())
                left[i] = 0;
            else
                left[i] = st.top() + 1;
            
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }

            if(st.empty())
                right[i] = n - 1;
            else
                right[i] = st.top() - 1;
            
            st.push(i);
        }

        int mx = 0;
        for(int i = 0; i < n; i++){
            int height = h[i] * (right[i] - left[i] + 1);
            mx = max(mx, height);
        }
        return mx;
    }
};
