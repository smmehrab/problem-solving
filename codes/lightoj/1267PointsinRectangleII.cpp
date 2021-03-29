#include<bits/stdc++.h>
using namespace std;
 
// (x,y) point, y2 -> if rectangle than top y, rect -> if rectangle , left-> if lower-left corner, id->index of query
// id->index of rectangle*

int sum[600007];

struct Point{
    int x, y,y2;
    bool rect;
    bool left;
    int id;
    Point(int a,int b, int f,bool c,bool d,int e){
        x = a;
        y = b;
        y2 = f;
        rect = c;
        left = d;
        id = e;
    }
};

struct Range{
    int start, end;
    Range(int start, int end){
        start = start;
        end = end;
    }
};

bool compare(Point a, Point b){
    if(a.x == b.x){
        if(a.left)
            return 1;
        if(b.left)
            return 0;
        return a.rect<b.rect;
    }
    return a.x<b.x;
}

void update(int current, int left, int right, int index){
    if(left==right){
        sum[current]++;
        return;
    }

    int mid = (left+right)>>1;
    (index<=mid) ? update(current<<1, left, mid, index) : update((current<<1)|1, mid+1, right, index);
    sum[current] = sum[current<<1] + sum[(current<<1)|1];
}

int query(int current, int left, int right, int start, int end){
    if(left>end || right<start) return 0;
    if(left>=start && right<=end) return sum[current];

    int mid = (left+right)>>1;
    int leftSum = query((current<<1), left, mid, start, end);
    int rightSum = query((current<<1)|1, mid+1, right, start, end);
    return (leftSum+rightSum);
}

int main(){
    int testCaseCount, pointCount, queryCount, x, y, x1, y1, len;
    cin >> testCaseCount;
    
    for(int testCase=1; testCase<=testCaseCount; testCase++){

        cin >> pointCount >> queryCount;

        vector<Point> points;
        vector<int> yCoordinates;

        for(int i=0; i<pointCount; i++){
            cin >> x >> y;
            points.push_back(Point(x, y, 0, false, false, 0));
            yCoordinates.push_back(y);
        }

        
        for(int i = 0; i<queryCount; ++i){
            cin >> x >> y >> x1 >> y1;
            
            points.push_back(Point(x,y,y1,true,true,i));
            yCoordinates.push_back(y);

            points.push_back(Point(x1,y,y1,true,false,i));
            yCoordinates.push_back(y1);
        }
        
        sort(points.begin(), points.end(), compare);
        sort(yCoordinates.begin(), yCoordinates.end());
          
        map<int,int>mp;
        len = yCoordinates.size();
        for(int i = 0; i<len; ++i) mp[yCoordinates[i]] = i+1;

        int results[queryCount], result;
        memset(sum,0,sizeof(sum));

        len = points.size();
        for(int i = 0; i<len; ++i){
            if(!points[i].rect){
                update(1, 1, len, mp[points[i].y]);
            }
            else{
                result = query(1,1,len,mp[points[i].y], mp[points[i].y2]);
                results[points[i].id] = (points[i].left) ? result :  result-results[points[i].id];
            }
        }

        // for(int i = 0;i<len; ++i) cout<< points[i].x << " " << points[i].y << " " << points[i].left << " " << points[i].rect << endl;
        
        cout << "Case " << testCase << ":" << endl;
        for(int i = 0; i<queryCount; ++i) cout << results[i] << endl;
    }

    return 0;
}