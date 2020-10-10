class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        });

        int shotCount = 1;
        int currentStart, currentEnd, end = points[0][1];
        for (vector<int> point : points) {
            currentStart = point[0];
            currentEnd = point[1];
            if (currentStart>end) shotCount++, end = currentEnd;
        }
    
        return shotCount;
    }
};