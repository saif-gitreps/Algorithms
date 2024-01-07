class Solution {
// bruteforce attempt worked till 13/18 cases.
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int count = 0;
        while(true){
            bool found = false;
            for(int k = 0; k < bank.size(); k++){
                int cnt = 0;
                for(int i = 0; i < startGene.size(); i++){
                    if(bank[k][i] != startGene[i]){
                        cnt ++;
                    }
                }
                if(cnt <= 1){
                    startGene = bank[k];
                    found = true; 
                    count++;
                    bank.erase(bank.begin() + k);
                    break;
                }
            }
            if(startGene == endGene){
                return count;
            }
            if(!found){
                break;
            }
        }
        return -1;      
    }
};

class Solution {
// working solution , we bascially bruteforce thorugh each char and check if it wasnt visited and if it is in bank then we do a bfs.
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> vis;
        queue<string> q;
        q.push(startGene);
        vis.insert(startGene);
        int count = 0;

        while(q.empty() == false){
            int n = q.size();
            
            for(int i = 0; i < n; i++){
                string curr_node = q.front();
                q.pop();

                if(curr_node == endGene){
                    return count;
                }

                for(auto c: "ACGT"){
                    
                    for(int j = 0; j < curr_node.size(); j++){
                        string check_node = curr_node;
                        check_node[j] = c;
                        if(!vis.count(check_node) && 
                            find(bank.begin(), bank.end() ,check_node) != bank.end()){
                                
                            q.push(check_node);
                            vis.insert(check_node);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
