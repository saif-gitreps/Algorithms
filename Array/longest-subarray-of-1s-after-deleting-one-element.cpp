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
