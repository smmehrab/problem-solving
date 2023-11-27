#include<iostream>
#include<climits>
using namespace std;

int n, balloons[20], visited[20], max_score;

void solve(int shot, int score) {
    if(shot==n) {
        max_score=max(max_score,score);
        return;
    }

    int new_score;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
                visited[i]=1;

                bool right_found = false, left_found = false;
                int right=1,left=1;
                for(int j=i-1;j>=0;j--) {
                    if(visited[j]==0) {
                        left_found = true;
                        left = balloons[j];
                        break;
                    }
                }
                for(int j=i+1;j<n;j++) {
                    if(visited[j]==0) {
                        right_found = true;
                        right = balloons[j];
                        break;
                    }
                }

                new_score = score;
                if(left_found && right_found)
                    new_score += (left*right);
                else if(!left_found && right_found)
                    new_score += right;
                else if(left_found && !right_found)
                    new_score += left;
                else 
                    new_score += balloons[i];
                solve(shot+1, new_score);

                visited[i]=0;
        }
    }
}

int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>balloons[i];
        visited[i]=0;
    }
    max_score=INT_MIN;
    solve(0, 0);
    cout << max_score << endl;
    return 0;
}