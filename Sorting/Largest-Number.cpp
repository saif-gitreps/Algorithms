bool comparator(string a, string b){
    if(a == b){
        return true;
    }
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i++] - '0' >= b[j++] - '0'){
            return true;
        }
        else{
            return false;
        }
    }
    if(i == a.size() && a[i - 1] > b[j]){
        return true;
    }
    else{
        return false;
    }
}
class Solution {
// naive attempt, wasnt handling the case 3 and 30 very well.
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> temp;
        
        for(auto num : nums){
            temp.push_back(to_string(num));
        }

        sort(temp.begin(), temp.end(), comparator);
        
        for(auto num: temp){
            ans += num;
        }
        return ans;
    }
};



bool comparator(string &a, string &b){
    return a + b > b + a;
}
class Solution {
// I was missing this comparator logic, this was so genious, example 1 + 0  > 0 + 1.
// also removing extra zeroes from the front.
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> temp;
        
        for(auto num : nums){
            temp.push_back(to_string(num));
        }

        sort(temp.begin(), temp.end(), comparator);
        
        for(auto num: temp){
            ans += num;
        }

        if(ans[0] == '0'){
            while(ans[0] == '0' && ans.size() > 1){
                ans.erase(0, 1);
            }
        }

        return ans;
    }
};
