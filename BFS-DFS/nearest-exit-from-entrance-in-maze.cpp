class Solution {
// was tricky but similar to island prblem.
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        int mn = 1;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        int n = maze.size(), m = maze[0].size();
        int seq[] = {0, 1, 0, -1, 0};

        while(q.empty() == false){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j ++){
                    
                    int r = row + seq[j];
                    int c = col + seq[j + 1];

                    if(r < 0 || c < 0 || r >= n || c >= m || maze[r][c] == '+'){
                        continue;
                    }
                    if(r == 0 || c == 0 || r == n-1 || c == m-1){
                        return mn;
                    }

                    maze[r][c] = '+';
                    q.push({r, c});
                }
            }
            mn++;
        }
        return -1;
    }
};
