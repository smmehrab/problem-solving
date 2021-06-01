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
    int kthFactor(int n, int k) {
        int nth=0;
        for(int i=1; i<=n/2; i++) {
            if(n%i==0){
                if(++nth==k) return i;
            }
        }
        return (++nth==k) ? n : -1; 
    }
};