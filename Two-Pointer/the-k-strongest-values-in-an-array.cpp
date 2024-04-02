int med;
// naive solution.
bool comparator(int &a, int &b){
    if (abs(a - med) > abs(b - med)){
        return true;
    }
    else if(abs(a - med) == abs(b - med)){
        return a > b;
    }
    return false;
}

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        med = arr[(n - 1) / 2];

        sort(arr.begin(), arr.end(), comparator);

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

// best sol
vector<int> getStrongest(vector<int>& arr, int k) {
    sort(begin(arr), end(arr));
    int i = 0, j = arr.size() - 1;
    int med = arr[(arr.size() - 1) / 2];
    while (--k >= 0)
        if (med - arr[i] > arr[j] - med)
            ++i;  
        else
            --j;
    arr.erase(begin(arr) + i, begin(arr) + j + 1);
    return arr;
}
