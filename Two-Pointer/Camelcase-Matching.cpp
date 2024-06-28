class Solution {
// first attempt worked. Idea was that first we will count the number of request caps in pattern.
// then we will try to match the entire pattern and also count the caps in query, then we check.
// The reason for counting caps is because there maybe a situation where we ran out of J iterator (for pattern).
// and we still have remaining query string where there maybe alot more caps. [q = FootBallCity, p = FB]
public:
    vector<bool> camelMatch(vector<string>& queries, string p) {
        vector<bool> ans;
        int req_ucase = 0;
        for(int i = 0; i < p.size(); i++){
            if (isupper(p[i]))
                req_ucase++;
        }

        for (string q : queries) {
            int i = 0, j = 0, ucase_cnt = 0;
            
            while (i < q.size()) {
                if (isupper(q[i])) {
                    ucase_cnt++;
                }

                if (j < p.size() && q[i] == p[j]) {
                    i++;
                    j++;
                } else {
                    i++;
                }
                
            }
            
            if (ucase_cnt == req_ucase && j == p.size()) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
