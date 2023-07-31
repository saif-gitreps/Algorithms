class Solution {
//attempt 1 , worked till 70 cases.
public:
    int longestSubarray(vector<int>& a) {
        int marked = -1;
        int seq = 0;
        int max_seq = -1;
        for(int i=0;i<a.size();i++){
            if(a[i]==0){
                if(marked==-1){
                    marked = i;
                }
                else if(marked!=1){
                    seq = abs((marked+1)-i);
                    marked = i;
                }
            }
            if(a[i]==1){
                seq++;
                max_seq=max(max_seq,seq);
            }
        }
        if(seq==0){
            return 0;
        }
        return max_seq==a.size()?max_seq-1:max_seq;
    }
};

class Solution {
// solution passed, the fastest algorithm for this there is, dont ask me how i solved it, i just pulled it out of thin air . 
// good shi i guess.
public:
    int longestSubarray(vector<int>& a) {
        int marked = -1;
        int seq = 0;
        int max_seq = -1;
        for(int i=0;i<a.size();i++){
            if(a[i]==0){
                if(marked==-1){
                    marked = i;
                }
                else if(marked!=-1){
                    seq = abs((marked+1)-i);
                    marked = i;
                }
            }
            if(a[i]==1){
                seq++;
                max_seq=max(max_seq,seq);
            }
        }
        if(max_seq==-1){
            return seq;
        }
        return max_seq==a.size()?max_seq-1:max_seq;
    }
};
class Solution {
// not my solution , but cheecky solution

public:
    int longestSubarray(vector<int>& nums) {
       int count=0;
       vector<int> ans;
       for(int i=0;i<nums.size();i++){
           if (nums[i]==1)
               count++;
            else{
                ans.push_back(count);
                count = 0;
            }
       }
       ans.push_back(count);
       int l = 0;
       for(int i=1;i<ans.size();i++)
           l = max(l,ans[i-1]+ans[i]);
        return (ans.size()==1)?ans[0]-1:l;
    }
};
