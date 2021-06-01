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
    string decodeString(string s) {
        stack<string> decodings;
        string toBeDecoded, decoding, decoded="", number;
        int numberOfTimes;
        
        for(char c : s) {
            if(c!=']') {
                decoding = "";
                decoding += c;
            }
            else {
                toBeDecoded = "";
                while(!decodings.empty() && decodings.top()!="[") {
                    toBeDecoded = decodings.top()+toBeDecoded;
                    decodings.pop();
                }
                decodings.pop();

                numberOfTimes = 1;
                number = "";
                while(!decodings.empty() && decodings.top()>="0" && decodings.top()<="9") {
                    number = decodings.top()+number;
                    decodings.pop();
                }
                if(number!="") numberOfTimes = stoi(number);

                decoding = "";
                while(numberOfTimes--) decoding += toBeDecoded;
            }

            decodings.push(decoding);
        }

        while(!decodings.empty()) {
            decoded = decodings.top()+decoded;
            decodings.pop();
        }
        return decoded;
    }
};