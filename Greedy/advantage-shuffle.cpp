class Solution {
// atleast the idea of using BS was right.
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s;
        for(auto num : nums1){
            s.insert(num);
        }
        for(int i = 0; i < nums2.size(); i++){
            auto it = s.upper_bound(nums2[i]);
            if (it != s.end()) {
                nums1[i] = *it;
                s.erase(it);
            }
            else{
                nums1[i] = *s.begin();
                s.erase(s.begin());
            }
        }
        return nums1;
    }
};
