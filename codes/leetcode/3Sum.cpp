/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;

        if (nums.size() > 2)
        {

            bool isAllZero = true;
            for (int index = 0; index < nums.size(); index++)
            {
                if (nums[index] != 0)
                    isAllZero = false;
            }

            if (isAllZero)
                return vector<vector<int>>{{0, 0, 0}};

            sort(nums.begin(), nums.end());
            for (int index = 0; index < nums.size() - 2; index++)
            {
                int low = index + 1;
                int high = nums.size() - 1;
                while (low < high)
                {
                    if (nums[index] + nums[low] + nums[high] == 0)
                    {
                        vector<int> triplet{nums[index], nums[low], nums[high]};
                        sort(triplet.begin(), triplet.end());
                        result.push_back(triplet);
                        low++;
                        high--;
                    }
                    else if (nums[index] + nums[low] + nums[high] < 0)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }

            set<vector<int>> s(result.cbegin(), result.cend());
            result = vector<vector<int>>(s.cbegin(), s.cend());
        }

        return result;
    }
};