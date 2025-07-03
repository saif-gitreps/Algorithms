class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxi = 0;
        while(left < right){
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = h * w;
            maxi = max(maxi, area);
            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else {
                left++;
                right--;
            }
        }
        return maxi;
    }
};


class Solution {
// SUI solved on my own in 8 minutes with logic.
public:
    int maxArea(vector<int>& height) {
        int L = 0;
        int R = height.size()-1;
        int max_area = 0;
        while (L < R) {
            max_area = max(
                max_area,
                min(height[L], height[R]) * (R-L)
            );
            if (height[L] <= height[R]) {
                L++;
            } else {
                R--;
            }
        }

        return max_area;
    }
};
