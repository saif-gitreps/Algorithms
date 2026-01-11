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
            int height = h[i]  * (right[i] - left[i] + 1);
            mx = max(mx, height);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            if (i == 0){
                for(int j = 0; j < m; j++){
                    dp[i][j] = matrix[i][j] - '0';
                }
                mx = max(largestRectangleArea(dp[i]), mx);
            }
            else{
                for(int j = 0; j < m; j++){
                    if(matrix[i][j] == '1'){
                        dp[i][j] = (matrix[i][j] - '0') + dp[i - 1][j];
                    }
                }
                mx = max(largestRectangleArea(dp[i]), mx);
            }
        }
        return mx;
    }
};
