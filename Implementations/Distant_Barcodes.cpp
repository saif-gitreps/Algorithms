class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
      // worked till 18 cases.
        map<int,int> mp;
        for(int i=0;i<b.size();i++){
            mp[b[i]]++;
        }
        vector<int> ans;
        ans.push_back(b[0]);
        int curr = b[0];
        mp[curr]--;
        for(int i=1;i<b.size();i++){
            for(auto x: mp){
                    if(x.second>0 && curr!=x.first){
                        curr = x.first;
                        mp[curr]--;
                        break;
                    }
                    else{
                        continue;
                    }
               }
            if(ans.back()!=curr)
                    ans.push_back(curr);
        }
        return ans;
    }

};

class Solution {
//worked till 18 cases.
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        map<int,int> mp;
        sort(b.begin(),b.end());
        for(int i=0;i<b.size();i++){
            mp[b[i]]++;
        }
        vector<int> ans;
        int curr = -1;

        for(int i=0;i<b.size();i++){
            for(auto x: mp){
                    if(x.second>0 && curr!=x.first){
                        curr = x.first;
                        mp[curr]--;
                        break;
                    }
                    else{
                        continue;
                    }
               }
            //  if(ans.back()!=curr)
                    ans.push_back(curr);
        }
        return ans;
    }

};


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        if(b.size()<=1){
            return b;
        }
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<b.size();i++){
            mp[b[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
        }
        while(pq.top().first>0){
            pair<int,int> pair1 = pq.top();pq.pop();
            ans.push_back(pair1.second);
            pair1.first--;
            pair<int,int> pair2 = pq.top();pq.pop();
            if(pair2.first>0){
                ans.push_back(pair2.second);
                pair2.first--;
            }
            pq.push(pair1);
            pq.push(pair2);
        }
        return ans;
    }

};
