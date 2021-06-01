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
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> permutation; 

        multiset<int> mSet;
        for(int number : A)
            mSet.insert(number);
        
        for(int number : B) {
            auto smallestGreater = mSet.upper_bound(number);
            if(smallestGreater == mSet.end())
                smallestGreater = mSet.begin();
            permutation.push_back(*smallestGreater);
            mSet.erase(smallestGreater);
        }
        
        return permutation;
    }
};