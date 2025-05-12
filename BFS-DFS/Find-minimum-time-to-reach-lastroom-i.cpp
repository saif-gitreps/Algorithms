class Solution {
public:
    bool isValid(const int row, const int col, const std::vector<std::vector<int>>& grid)
    {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size();
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<>> weightToRowToColPQ;

        weightToRowToColPQ.push({0, 0, 0});

        std::vector<std::vector<int>> minTimeToReach(moveTime.size(), std::vector<int>(moveTime.front().size(), INT_MAX));

        const std::array<int, 5> transformations = {0, 1, 0, -1, 0};

        while(weightToRowToColPQ.empty() == false)
        {
            int weight = weightToRowToColPQ.top()[0];
            int row = weightToRowToColPQ.top()[1];
            int col = weightToRowToColPQ.top()[2];
            weightToRowToColPQ.pop();

            for(int i = 1; i < transformations.size(); i++)
            {
                int xformRow = transformations[i] + row;
                int xformCol = transformations[i - 1] + col;
                
                if(isValid(xformRow, xformCol, moveTime) == false) continue;

                int newWeight = std::max(moveTime[xformRow][xformCol], weight) + 1;
                if(newWeight < minTimeToReach[xformRow][xformCol])
                {
                    minTimeToReach[xformRow][xformCol] = newWeight;
                    weightToRowToColPQ.emplace(std::vector<int>{newWeight, xformRow, xformCol});
                }
            }
        }

        return minTimeToReach.back().back();
    }
};
