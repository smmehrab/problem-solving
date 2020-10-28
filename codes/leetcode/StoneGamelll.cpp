// class Solution {
// private:
//     int n, totalScore;
//     int maximumScoreDifference[50010];

//     int findMaximumScoreDifference(int i, vector<int>& scores) {
//         if(maximumScoreDifference[i]!=INT_MIN) return optimalMove[i];
//         else {
//             int scoreDifference = INT_MIN;
//             scoreDifference = max(scoreDifference, scores[i]-findMaximumScoreDifference(i+1, scores));
//             if(i+1<n) scoreDifference = max(scoreDifference, scores[i]+scores[i+1]-findMaximumScoreDifference(i+1, scores));
//             if(i+2<n) scoreDifference = max(scoreDifference, scores[i]+scores[i+1]+scores[i+2]-findMaximumScoreDifference(i+1, scores));
//             return maximumScoreDifference[i]=scoreDifference;
//         }
//     }

// public:
//     string stoneGameIII(vector<int>& scores) {
//         n = scores.size();
//         for(int i=0; i<n; i++) maximumScoreDifference[i] = INT_MIN;
//         int maximumScoreDifferenceBetweenAliceAndBob = findMaximumScoreDifference(0, scores);
//         return (maximumScoreDifferenceBetweenAliceAndBob>0) ? "Alice" : (maximumScoreDifferenceBetweenAliceAndBob<0) ? "Bob" : "Tie"; 
//     }
// };

class Solution {
public:
    string stoneGameIII(vector<int>& scores) {
        int n = scores.size();
        int first=0, second=0, third=0, index=n-1;
        while(index>=0) {
            int scoreDifference = scores[index]-first;
            if(index+1<n) scoreDifference = max(scoreDifference, scores[index]+scores[index+1]-second);
            if(index+2<n) scoreDifference = max(scoreDifference, scores[index]+scores[index+1]+scores[index+2]-third);
            third = second;
            second = first;
            first = scoreDifference;
            index--;
        }
        int maximumScoreDifferenceBetweenAliceAndBob = first;
        return (maximumScoreDifferenceBetweenAliceAndBob>0) ? "Alice" : (maximumScoreDifferenceBetweenAliceAndBob<0) ? "Bob" : "Tie"; 
    }
};