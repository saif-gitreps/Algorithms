class Solution {
// I just simulated it in a very manual way.
// tho it is accepted, there is an automated way to it.
public:
    void change_dir(char &dir, int c) {
        if (dir == 'N') {
            if (c == -1) 
                dir = 'E'; 
            else
                dir = 'W'; 
        } else if (dir == 'S') {
            if (c == -1)
                dir = 'W';
            else 
                dir = 'E';
        } else if (dir == 'E') {
            if (c == -1)
                dir = 'S';
            else 
                dir = 'N';
        } else {
            if (c == -1)
                dir = 'N';
            else
                dir = 'S';
        }
    }

    int get_farthest(int x, int y) {
        return pow(x, 2) + pow(y, 2);
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int farthest = 0, x = 0, y = 0;
        char dir = 'N';
        map<pair<int, int>, int> mp;

        for (auto obstacle : obstacles) {
            mp[{obstacle[0], obstacle[1]}] = 1;
        }

        for (auto c : commands) {
            if (c < 0) {
                change_dir(dir, c);
            } else {
                if (dir == 'N') {
                    int count = c;
                    while (count-- && mp.find({x, y + 1}) == mp.end()) {
                        y += 1;
                        farthest = max(farthest, get_farthest(x, y));
                    }
                }
                if (dir == 'S') {
                    int count = c;
                    while (count-- && mp.find({x, y - 1}) == mp.end()) {
                        y -= 1;
                        farthest = max(farthest, get_farthest(x, y));
                    }
                }
                if (dir == 'E') {
                    int count = c;
                    while (count-- && mp.find({x + 1, y}) == mp.end()) {
                        x += 1;
                        farthest = max(farthest, get_farthest(x, y));
                    }
                }
                if (dir == 'W') {
                    int count = c;
                    while (count-- && mp.find({x - 1, y}) == mp.end()) {
                        x -= 1;
                        farthest = max(farthest, get_farthest(x, y));
                    }
                }
            }
        }

        return farthest;
    }
};

public class Solution {
/*
  Best example of automating the directions. This is self explanatory.
  
  North, direction = 0, directions[direction] = {0, 1}
  East,  direction = 1, directions[direction] = {1, 0}
  South, direction = 2, directions[direction] = {0, -1}
  West,  direction = 3, directions[direction] = {-1, 0}
  
  direction will increase by one when we turn right, 
  and will decrease by one (or increase by three) when we turn left

  direction = (direction + 3) % 4;
  This line is handling the left turn (-2 command). To understand why it's direction + 3 modulo 4, 
  let's break it down:
  
  First, recall the directions array:
  javaCopyint[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  These represent North (0), East (1), South (2), and West (3) respectively.
  When we turn left, we're moving counterclockwise in this order: North -> West -> South -> East -> North
  In terms of array indices, this translates to: 0 -> 3 -> 2 -> 1 -> 0
  Now, let's consider what happens when we subtract 1 from each index:
  
  0 - 1 = -1, but we want 3 (West)
  3 - 1 = 2 (South)
  2 - 1 = 1 (East)
  1 - 1 = 0 (North)
  
  
  To achieve this cycling behavior and avoid negative numbers, we can add 3 and take the modulo 4:
  
  (0 + 3) % 4 = 3 (West)
  (3 + 3) % 4 = 2 (South)
  (2 + 3) % 4 = 1 (East)
  (1 + 3) % 4 = 0 (North)
  
  So, (direction + 3) % 4 is mathematically equivalent to (direction - 1 + 4) % 4, 
  which achieves the desired left turn.
  Using + 3 instead of - 1 is a common trick in programming to avoid dealing with negative numbers when 
  working with modular arithmetic. 
  It's especially useful when the starting number could be 0, as subtracting might lead to a negative number 
  before the modulo operation.
*/

    public int robotSim(int[] commands, int[][] obstacles) {
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Set of obstacles indexes in the format of : obstacle[0] + " " + obstacle[1]
        Set<String> obstaclesSet = new HashSet<>();
        for (int[] obstacle : obstacles) {
            obstaclesSet.add(obstacle[0] + " " + obstacle[1]);
        }

        int x = 0, y = 0, direction = 0, maxDistSquare = 0;
        for (int i = 0; i < commands.length; i++) {
            if (commands[i] == -2) { // Turns left
                direction = (direction + 3) % 4;
            } else if (commands[i] == -1) { // Turns right
                direction = (direction + 1) % 4;
            } else { // Moves forward commands[i] steps
                int step = 0;
                while (step < commands[i] 
                       && (!obstaclesSet.contains(
                           (x + directions[direction][0]) + " " + (y + directions[direction][1]))
                          )
                      ) {
                    x += directions[direction][0];
                    y += directions[direction][1];
                    step++;
                }
            }
            maxDistSquare = Math.max(maxDistSquare, x * x + y * y);
        }

        return maxDistSquare;
    }
};
