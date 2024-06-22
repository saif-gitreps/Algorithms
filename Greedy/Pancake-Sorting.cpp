// two attempts, cant solve, bruh this greedy thing is trash fr.

class Solution {
public:
    bool is_sorted(vector<int> &a){
        for(int i = 1; i < a.size(); i++){
            if(a[i - 1] > a[i])
                return false;
        }
        return true;
    }
    vector<int> pancakeSort(vector<int>& a) {
        vector<int> ans;
        while(!is_sorted(a)){
            for(int i = 1; i < a.size(); i++){
                if(a[i - 1] > a[i]){
                    reverse(a.begin() + i - 1, a.begin() + i + 1);
                    ans.push_back(i + 1);
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    bool is_sorted(vector<int> &a){
        for(int i = 1; i < a.size(); i++){
            if(a[i - 1] > a[i])
                return false;
        }
        return true;
    }
    vector<int> pancakeSort(vector<int>& a) {
        vector<int> ans;
        int shift = 1, reverse_index = 2;
        while(!is_sorted(a)){
            if (shift % 2 == 1) {
                reverse(a.begin(), a.end());
                ans.push_back(a.size());
            } else {
                reverse(a.begin(), a.begin() + reverse_index);
                ans.push_back(reverse_index++);
            }
            shift++;
        }

        return ans;
    }
};
