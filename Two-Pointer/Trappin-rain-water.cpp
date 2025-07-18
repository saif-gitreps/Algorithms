class Solution { // 4 ms, faster than 89.31%
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        for (int i = 1; i < n; ++i) 
            leftMax[i] = max(height[i-1], leftMax[i-1]);
        for (int i = n-2; i >= 0; --i) 
            rightMax[i] = max(height[i+1], rightMax[i+1]);
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int waterLevel = min(leftMax[i], rightMax[i]);
            if (waterLevel >= height[i]) ans += waterLevel - height[i];
        }
        return ans;
    }
};

class Solution {
// lesgo baby figured it out
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_left = 0;
        int max_right = 0;
        int ans = 0;

        while (true) {
            if (height.size() % 2 == 0) {
                if (left == right) {
                    break;
                }
            } else {
                if (left > right) {
                    break;
                }
            }
            max_left = max(max_left, height[left]);
            max_right = max(max_right, height[right]);

            if (left == right) {
                if (height[left] < min(max_left, max_right)) {
                    ans += (min(max_left, max_right) - height[left]);
                }
            } else {
                if (height[left] < min(max_left, max_right)) {
                    ans += (min(max_left, max_right) - height[left]);
                }
                if (height[right] < min(max_left, max_right)) {
                    ans += (min(max_left, max_right) - height[right]);
                }
            }

            // debug(ans);
            // debug("--");

            if (height[left] <= height[right]){
                left++;
            } else if (height[left] > height[right]) {
                right--;
            } 
        }    

        return ans;  
    }

};
