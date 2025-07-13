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


class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int> gaps(n + 1);

        // Calculate the first and last gap separately
        gaps[0] = st[0];  // Free time before the first meeting
        gaps[n] = eventTime - et[n - 1];  // Free time after the last meeting

        // Compute gaps between meetings
        for(int i = 1; i < n; i++){
            gaps[i] = st[i] - et[i - 1];
        }

        // Compute prefix sum for efficient range sum calculation
        vector<int> pref(n + 2, 0);
        for(int i = 1; i <= n + 1; i++){
            pref[i] = pref[i - 1] + gaps[i - 1];
        }

        int ans = 0;
        for(int i = k + 1; i <= n + 1; i++){
            ans = max(ans, pref[i] - pref[i - (k + 1)]);
        }

        return ans;              
    }
};
