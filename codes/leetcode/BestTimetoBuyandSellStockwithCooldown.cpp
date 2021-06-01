/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
/* 
    ** 3 States **

    (1)
    a -> hold -> a
      -> buy -> b

    (2) 
    b -> hold -> b
      -> sell -> c
    
    (3)
    c -> hold -> a

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a=0, b=INT_MIN, c=0, previousA;
        for(int price : prices){
            previousA = a;
            a = max(a, c);
            c = b + price;
            b = max(b, previousA-price);
        }
        return max(a, c);
    }
};