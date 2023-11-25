class Solution {
  // Solid attempt , not gonna lie from me.
public:
    string removeKdigits(string nums, int k) {
        if(k == nums.size()){
            return "0";
        }
        int limit = k;
        for(int i = 1 ; i < nums.size(); i++){
            if(k == 0){
                break;
            }
            if(k && nums[i-1]-'0' < nums[i]-'0'){
                swap(nums[i-1], nums[i]);
                k--;
            }
            else{
                k--;
            }
        }
        string str = "";
        for(int i = limit; i < nums.size(); i++){
            if(str == "" && nums[i] == '0'){
                continue;
            }
            str += nums[i];
        }
        if(str == ""){
            return "0";
        }
        return str;
    }
};


class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), keep = n - k;
        for (char c : num) {
            while (k && res.size() && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(keep);
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};
