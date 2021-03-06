/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s == "")
            return true;

        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (!isalnum(s[left]))
                left++;
            else if (!isalnum(s[right]))
                right--;
            else if (tolower(s[left]) != tolower(s[right]))
                return false;
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};