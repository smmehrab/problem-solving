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
private:
    int findPivot (vector<int> rotatedSortedArray){
        int low = 0, high = (rotatedSortedArray.size()-1), mid; 
        while (low < high) {
            mid = low + (high-low)/2; 
            if(rotatedSortedArray[mid]>rotatedSortedArray[high]) low = mid+1;
            else high = mid;
        }
        return low;
    }
    
    int binarySearch (int low, int high, vector<int> rotatedSortedArray, int target) {
        int mid;
        while (low <= high) {
            mid = low + (high-low)/2;    
            if (rotatedSortedArray[mid] == target) return mid; 
            else if (rotatedSortedArray[mid] > target) high = mid-1;
            else  low = mid+1;
        }
        return -1 ; 
    }

public:
    int search(vector<int>& rotatedSortedArray, int target) {
        int size = rotatedSortedArray.size() ;  
        int pivot = findPivot (rotatedSortedArray);         
        if (rotatedSortedArray[pivot] == target) return pivot ;
        int index = binarySearch(pivot, size-1, rotatedSortedArray, target);
        return (index != -1) ? index : binarySearch(0 , pivot-1, rotatedSortedArray, target);
    }
};