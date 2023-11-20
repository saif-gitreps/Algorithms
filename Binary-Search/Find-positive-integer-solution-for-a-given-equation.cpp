/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

// bruteforce solution 1/many.
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        vector<vector<int>> ans;
        int y = 1000;
        for(int x = 1; x <= 1000; x++){
            while(y > 1 && cf.f(x,y) > z){
                y--;
            }
            if(cf.f(x,y) == z){
                ans.push_back({x, y});
            }
        }
        return ans;
    }
};



/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
//BS solution.
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        vector<vector<int>> ans;
        for(int i = 1; i <= 1000; i++){
            int left = 1;
            int right = 1000;
            while(left <= right){
                int mid = (left+right)/2;
                if(cf.f(i,mid) == z){
                    ans.push_back({i,mid});
                    break;
                }
                else if(cf.f(i,mid) > z){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            if(cf.f(i,1) > z){
                break;
            }
        }
        return ans;
    }
};
