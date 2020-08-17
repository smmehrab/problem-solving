#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& numbers) {
        vector<int>result;
        for(int number : numbers)
        {
            if(numbers[abs(number)-1] < 0) result.push_back(abs(number));
            numbers[abs(number)-1] *= -1;
        }
        return result;
    }
};