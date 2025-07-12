class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    vector<int> gap(1, startTime[0]);
    for(int i = 1; i < startTime.size(); ++i) gap.push_back(startTime[i] -  endTime[i-1]);
    gap.push_back(eventTime - endTime.back());
    int ans = 0, sum = 0;
    for(int i = 0; i < gap.size(); ++i){
        sum += gap[i] - ((i >=  k+1)? gap[i - (k+1)] : 0);
        ans = max(ans, sum);
    }
    return ans;
}
};

class Solution {
public:
    static int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int n=startTime.size();
        int busy=0;
        for (int i=0; i < k; i++) 
            busy+=endTime[i]-startTime[i];

        if (n==k) return eventTime-busy;

        int ans=startTime[k]-busy;//1st window

        // sliding window
        for (int l=0, r=k; r<n; l++, r++) {
            busy+=(endTime[r]-startTime[r])-(endTime[l]-startTime[l]);
            int end=(r==n-1)?eventTime:startTime[r+1];
            int start=endTime[l];
            ans=max(ans, end-start-busy);
        }
        return ans;
    }
};

