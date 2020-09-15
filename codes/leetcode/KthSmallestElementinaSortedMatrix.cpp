class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap; 
        for(vector<int> row : matrix) {
            for(int element : row) {
                maxHeap.push(element);
                if(maxHeap.size()>k) maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};