class Solution {
private:
    int n;
    string ipString;
    vector<string> ipAddresses;
    
    void backtrack(int start, string segment, int segmentNo) {
        if(start>n || segmentNo>4) 
            return;

        if(start==n && segmentNo==4) {
            segment.pop_back();
            ipAddresses.push_back(segment);
            return;
        }

        for(int i=start; i<n; i++) {
            segment.push_back(ipString[i]);
            int segmentValue = stoi(segment.substr(start+segmentNo));
            // 0-255 Constraint
            if(segmentValue<0 || segmentValue>255)
                return;
            // No Leading Zero Constraint
            if((segmentValue>0 && segment[start+segmentNo]=='0') || (i>start && segmentValue==0) )
                return;
            // Continue Backtracking
            backtrack(i+1, segment+".", segmentNo+1);
        }
    }

public:
    vector<string> restoreIpAddresses(string ipString) {
        this->n = ipString.size();
        this->ipString = ipString;
        if(n!=0) 
            backtrack(0, "", 0);
        return ipAddresses;
    }
};