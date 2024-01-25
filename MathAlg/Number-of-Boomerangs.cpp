class Solution {
// We take one individual point, We then try to find the distance between that point
// and other points. we create a new map for every individual point.
// for every two point that is a boomerage , there will be n * n - 1 valid boomerange. 
// now you might be confused what about those cases where only a single distance is there in mp.
// then the formula will handle the case 1 * ( 1 - 0 ) is 0.
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            unordered_map<int, int> mp;
            for(int j = 0 ; j < n; j++){
                // distance formula x = root(sqr(x2-x1) + sqr(y2-y1)).
                int d = pow(points[i][0] - points[j][0], 2) +
                        pow(points[i][1] - points[j][1], 2);
                mp[d] ++;
            }
            for(auto d : mp){
                if(d.second >= 1){
                    ans += (d.second * (d.second - 1));
                }
            }
        }
        return ans;
    }
};
