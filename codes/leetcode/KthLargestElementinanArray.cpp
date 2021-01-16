class Solution {
public:
    int findKthLargest(vector<int>& numbers, int k) {
        priority_queue<int> heap;
        for(int number : numbers) heap.push(number);
        while(k > 1){
            heap.pop();
            k--;
        }
        return heap.top();
    }
};