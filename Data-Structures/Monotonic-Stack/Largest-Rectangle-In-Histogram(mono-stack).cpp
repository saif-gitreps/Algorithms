class Solution {
/*  
  Mono tonic stack means , a stack that only keeps values in ASCending.
  ionno this soln makes no sense.
*/
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int mx = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || h[st.top()] >= h[i])){
                int height = h[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() - 1;
                }
                mx = max(mx, width * height);
            }
            st.push(i);
        }
        return mx;
    }
};
