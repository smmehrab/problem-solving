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