class Solution {

/*
  Passed 25/50 cases.
  The problem i understood with this is,i did it greedily where it does merge but there is nested merge as well
  for which i need to do like a dfs or recursion. Cannot be solved iteratively.
  I did my best. tough problem init.
  
  {{"David","David0@m.co","David1@m.co"},
  {"David","David3@m.co","David4@m.co"},
  {"David","David4@m.co","David5@m.co"},
  {"David","David2@m.co","David3@m.co"},
  {"David","David1@m.co","David2@m.co"}}
*/

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        sort(accounts.begin(), accounts.end(), [](const vector<string>& a, const vector<string>& b) {
            return a[0] < b[0];
        });

        for (int i = 1; i < accounts.size(); i++) {
            if (accounts[i - 1][0] == accounts[i][0]) {
                int count = 0;
                while (i < accounts.size() && accounts[i - 1][0] == accounts[i][0]) {
                    accounts[i - 1][0] += ('0' + count);
                    count += 2;
                    i++;
                }
                accounts[i - 1][0] += ('0' + count);
            }
        }

        map<string, string> mp;
        vector<vector<string>> ans;

        for (auto account : accounts) {
            bool flag = false;
            string prev;
            for (int i = 1; i < account.size(); i++) {
                if (mp.find(account[i]) != mp.end()) {
                    flag = true;
                    prev = mp[account[i]];
                    break;
                }
            }
            if (!flag) {
                for (int i = 1; i < account.size(); i++) {
                    mp[account[i]] = account[0];
                }
            } else {
                for (int i = 1; i < account.size(); i++) {
                    mp[account[i]] = prev;
                }
            }
        }

        for (auto account : accounts) {
            vector<string> temp;
            temp.push_back(account[0]);
            
            for (const auto& it : mp) {
                if (it.second == account[0]) 
                    temp.push_back(it.first);
            }

            if (temp.size() > 1) {
                for (int i = temp[0].size() - 1; i >= 0 && isdigit(temp[0][i]); i --)
                    temp[0].pop_back();

                ans.push_back(temp);
            }
        }

        return ans;        
    }
};
