class Solution {
// Was a bit tricky for me idk, not the usual easy ones. 
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        sort(a.begin(), a.end());
        int mn = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 1; i < a.size(); i ++) {
            mn = min(mn, abs(a[i - 1] - a[i]));
        }

        for (int i = 1, j = 0; i < a.size() && j < a.size(); ) {
            if (i == j) { 
                i++;
                continue;
            }

            if (abs(a[i] - a[j]) == mn) {
                ans.push_back({a[j], a[i]});
                i++;
            }

            else j++; 
        }

        return ans;
    }
};

// not my solution but we didnt need to do those pointer shi i did, we could just comapre the adjacents.
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    
    vector<vector<int>> result;
    int min_diff = INT_MAX;
    
    // find min difference
    for (int i = 0; i < arr.size() - 1; ++i) {
        min_diff = min(arr[i + 1] - arr[i], min_diff);
    }
    
    // form a list of pairs with min difference, ascending  
    for (int i = 0; i < arr.size() - 1; ++i) {
        if (arr[i + 1] - arr[i] == min_diff)
            result.push_back({arr[i], arr[i + 1]});
    }
    return result;        
}
