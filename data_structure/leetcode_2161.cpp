class Solution {
  // first attempt, i worked hard on this one ,didnt want to discard them.
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a;
        vector<int> same;
        priority_queue<int> pq;
        set<int> s;
        for(int i=0;i<nums.size();i++){ 
            if(nums[i]==pivot){
                same.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                s.insert(nums[i]);
            }
            else{
                pq.push(nums[i]);
            }
        }
        while(pq.empty()!=true){
            a.push_back(pq.top());
            pq.pop();
        }
        for(auto x:same){
            a.push_back(x);
        }
        for(auto x: s){
            a.push_back(x);
        }
        return a;
        
    }
};
class Solution {
  // worked till 14 cases, then the test case became weird, i dont know why
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a;
        vector<int> same;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){ 
            if(nums[i]==pivot){
                same.push_back(nums[i]);
            }
            else if(nums[i]<pivot){
                pq.push(nums[i]);
            }
        }
        while(pq.empty()!=true){
            a.push_back(pq.top());
            pq.pop();
        }
        for(auto x:same){
            a.push_back(x);
        }
        for(auto x:nums){
            if(x>pivot){
                a.push_back(x);
            }
        }
        return a;
        
    }
};
