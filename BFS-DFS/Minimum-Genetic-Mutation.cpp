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
