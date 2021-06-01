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
    enum Status {
        Stamped, Ignored, Invalid
    };

    Status process(int index, string& stamp, string& target) {
        int count = 0, sSize = stamp.size(), tSize = target.size();
        for (int i=0; i<sSize && i+index<tSize; i++) {
            if (target[i+index] == '?') 
                continue;
            else if (target[i+index] == stamp[i])
                count++;
            else {
                count = -1;
                break;
            }
        }

        if (count>0) {
            for(int i=0; i<sSize && i+index<tSize; i++) 
                target[i+index] = '?';
        }

        return (count==0 ? Ignored : (count>0 ? Stamped : Invalid));
    }
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> moves;

        int sSize = stamp.size();
        int tSize = target.size();
        int qSize, index;

        queue<int> q;
        for (int i=0; i<=(tSize-sSize); i++)
            q.push(i);

        while (true) {
            qSize = q.size();
            for (int i=0; i<qSize; i++) {
                index = q.front();
                q.pop();

                Status status = process(index, stamp, target);
                if (status == Stamped)
                    moves.push_back(index);
                else if (status == Invalid)
                    q.push(index);
            }
            if(qSize == q.size())
                break;
        }
        
        if (q.size()>0)
            return {};
        
        reverse(moves.begin(),moves.end()); 
        return moves;
    }
};