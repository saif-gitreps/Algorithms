class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
    std::vector<int>::iterator i;
    i = unique(nums.begin(),nums.end());
    nums.resize( std::distance(nums.begin(),i));
    return nums.size();}
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIndex = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] != nums[i]) {
                nums[insertIndex] = nums[i];     
                insertIndex++;
            }
        }
        return insertIndex;
    }
};

class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        if(n==0||n==1)
        {
            return n;
        }
        for(int i=1;i<n;i++)
        {
           if(nums[i]!=nums[j])
            {
                j++;
                nums[j]=nums[i];

            }
        }
        return j+1;
    }
};
