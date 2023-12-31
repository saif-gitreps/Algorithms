class Solution {
// Idk had some idea in my mind wasnt working.
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prev = 10005;
        int count = 1;
        int mx = -1;
        for(int i = 0 ; i+1 < nums.size(); i++){
            if(i == 0){
                prev =  nums[i + 1] - nums[i];
                count++;
                mx = max(mx, count);
            }
            else{
                int sum = nums[i + 1] - nums[i];
                if(prev < 0 && sum >= 0){
                    count++;
                    prev = sum;
                    mx = max(mx, count);
                }
                else if(prev >= 0 && sum < 0){
                    count++;
                    prev = sum;
                    mx = max(mx, count);
                }
                else{
                    mx = max(mx, count);
                    count = 0;
                    prev = sum;
                }
            }
        }
        return mx;
    }
};

class Solution {
// respectable attempt. atleast worked on the initial test cases.
public:
    int calc(vector<int> nums) {
        int count = 0;
        int mx = -1;
        int n = nums.size();
        if(n <= 2){
            if(n == 2 && nums[0] < 0 && nums[1] >= 0){
                return 2;
            }
            else if(n == 2 && nums[0] >= 0 && nums[1] < 0){
                return 2;
            }
            return 1;
        }
        vector<int> temp;
        for(int i = 1; i < n; i++){
            temp.push_back(nums[i] - nums[i - 1]);
            //debug(temp[i]);
        }
        int prev = temp[0];
        count = 1; 
        mx = 1;
        for(int i = 1; i < temp.size(); i++){
            if((prev < 0 && temp[i] >= 0)){
                count++;
                mx = max(count, mx);
                prev = temp[i];
            }
            else if(prev >= 0 && temp[i] < 0){
                count++;
                mx = max(count, mx);
                prev = temp[i];
            }
            else{
                count = 0;
                prev = temp[i];
            }
        }
        return mx + 1;
    }

    int kev(int n, vector<int> a, vector<int> &temp){
        if(n == 0){
            temp.push_back(a[n]);
            int pick = calc(temp);
            temp.pop_back();
            int not_pick = calc(temp);
            return max(pick, not_pick);
        }

        int pick = 0;
        int not_pick = 0;
        temp.push_back(a[n]);
        pick = kev(n - 1, a, temp);
        temp.pop_back();

        not_pick = kev(n - 1, a, temp);

        return max(pick , not_pick);
    }

    int wiggleMaxLength(vector<int>& nums) { 
        vector<int> temp;
        int n = nums.size();
        return kev(n - 1,nums, temp);
    }
};
