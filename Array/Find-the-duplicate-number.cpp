class Solution {
// this was the Floyd - tortoise method, we got a slow pointer and fast pointer.
// Since there will be a repeat , the fast and slow will meet, after they meet, we reset
// the fast to the begining number and let slow remain as it is. 
// then we move both pointer by one (slow = slow->next , fast = fast->next , before it was fast = fast->next->next).
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
