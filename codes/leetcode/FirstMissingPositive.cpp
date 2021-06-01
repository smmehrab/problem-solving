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
    int firstMissingPositive(vector<int>& numbers) {
        int n = numbers.size();
        if(n==0) return 1;
        else if(n==1 && numbers[0]!=1) return 1;
        
        for(int i=0; i<n; i++)
            while(numbers[i]>0 && numbers[i]<n && numbers[i]-1!=i && numbers[i]!=numbers[numbers[i]-1])                         
                swap(numbers[i], numbers[numbers[i]-1]);
        
        for(int i=0; i<n; i++)
            if(numbers[i]-1!=i) 
                return i+1;
        
        return numbers[n-1]+1;
    }
};