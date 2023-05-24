class Solution {
    // took a hint of priority queue and did it myself.
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<score.size();i++){
            pq.push(make_pair(score[i],i));
        }
        map<int,string> mp;
        int i = 1;
        while(pq.empty()!=true){
            pair<int,int> p = pq.top();
            if(i==1){
                mp[p.second] = "Gold Medal";
            }
            else if(i==2){
                mp[p.second] = "Silver Medal";
            }
            else if(i==3){
                mp[p.second] = "Bronze Medal";
            }
            else{
                string num = to_string(i);
                mp[p.second] = num;
            }
            pq.pop();
            i++;
        }
        vector<string> v;
        for(auto s: mp){
            v.push_back(s.second);
        }
        return v;
    }
};