class Solution {
// uhh idk it was an awkwardly easy solution.
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        for(int i = 0; i + 2 < colors.size(); i++){
            if(colors[i] == colors[i + 1] && colors[i] == colors[i + 2] && colors[i] == 'A'){
                alice++;
            }
            else if(colors[i] == colors[i + 1] && colors[i] == colors[i + 2] && colors[i] == 'B'){
                bob++;
            }
        }
        if(alice <= bob){
            return false;
        }
        return true;
    }
};
