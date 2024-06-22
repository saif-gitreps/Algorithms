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


class Solution {
// Apparently, this was some sorting algorithm, didnt guess the trick properly as usual.
// our goal is to find the biggest number (and decreasing from there) and put it in its place
// First reverse from 0 till found location (Brings that element to the front) and then reverse 
// from 0 to the original position of that element. 
public:
    vector<int> pancakeSort(vector<int>& a) {
        vector<int> ans;

        for(int i = a.size(); i > 0; i--){
            for(int j = 0; j < a.size(); j++){
                if(a[j] == i){
                    reverse(a.begin(), a.begin() + j + 1);
                    ans.push_back(j + 1);
                    // reason for a.begin() + i is because
                    // we are putting that element in its respective place
                    // knowing that array values are 1...N(N == a.size)
                    reverse(a.begin(), a.begin() + i);
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};
