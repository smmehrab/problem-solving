class Solution {
public:
    bool isRobotBounded(string instruction) {
        pair<int,int> position = {0,0};
        vector<pair<int,int>> directions = {{0,1},{-1,0},{0,-1},{1,0}};
        int direction = 0;

        for(char step : instruction) {
            switch(step) {
                case 'G':
                    position.first += directions[direction].first;
                    position.second += directions[direction].second;
                    break;
                case 'L':
                    direction += 1;
                    direction %= 4;
                    break;
                case 'R':
                    direction += 3;
                    direction %= 4;
            }
        }
        
        return direction != 0 || (position.first == 0 && position.second == 0);
    }
};