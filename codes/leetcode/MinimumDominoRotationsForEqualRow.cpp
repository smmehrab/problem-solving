/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int minRotations = INT_MAX;

        // Case 1
        int AwithA0 = getSwapCount(A[0], A, B);
        minRotations = min(minRotations, AwithA0);

        // Case 2
        int AwithB0 = getSwapCount(B[0], A, B);
        minRotations = min(minRotations, AwithB0);
        
        // Case 3
        int BwithA0 = getSwapCount(A[0], B, A);
        minRotations = min(minRotations, BwithA0);
        
        // Case 4
        int BwithB0 = getSwapCount(B[0], B, A);
        minRotations = min(minRotations, BwithB0);

        return (minRotations == INT_MAX) ? -1 : minRotations;
    }

    int getSwapCount(int target, vector<int>& main, vector<int>& option) {
        int swapCount=0, n=main.size();
        for(int i=0; i<n; i++) {
            if(target == main[i]) continue;
            else if(target == option[i]) swapCount++;
            else return INT_MAX;
        }
        return swapCount;
    }
};