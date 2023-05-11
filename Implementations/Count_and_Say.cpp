class Solution {
public:
  // first attempt, works from 1-3 , yay.

    string ans(string num,int i,int n){
        if(i==n){
            return num;
        }
        else{
            unordered_map<int,int> mp;
            for(int i=0;i<num.size();i++){
                int number = num[i]-48;
                mp[number]++;
            }
            string sender = "";
            for(auto x: mp){
                sender += x.second+48;
                sender += x.first+48;
            }
            
            return ans(sender,i+1,n);
        }
    }

    string countAndSay(int n) {
         return ans("1",1,n);
    }
};

class Solution {
  // yay wroked till 3rd test case.
public:
string ans(string num,int i,int n){
        if(i==n){
            return num;
        }
        else{
            map<int,int> mp;
            queue<int> q;
            for(int k=0;k<num.size();k++){
                int number = num[k]-'0';
                mp[number]++;
                if(q.front()!=number){
                  q.push(number);
                }
            }

            string sender = "";
            while(q.empty()!=true){
               sender += mp[q.front()]+48;
               sender += q.front()+48;
               q.pop();
            }
            return ans(sender,i+1,n);
        }
    }

    string countAndSay(int n) {
         return ans("1",1,n);
    }

};
