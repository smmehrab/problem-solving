class Solution {
public:
    int largestOverlap(vector<vector<int>>& image1, vector<vector<int>>& image2) {
        int n=image1.size();
        int answer=0;

        for(int ro=-n; ro<n; ro++){
            for(int co=-n; co<n; co++){
                int overlap=0;
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        int i1=i+ro, j1=j+co;
                        if(i1<0 || j1<0 || i1>=n || j1>=n) continue;
                        if(image1[i1][j1]==1 && image2[i][j] ==1) overlap++;
                    }
                }
                answer = max(answer, overlap);
            }
        }

        return answer;
    }
};