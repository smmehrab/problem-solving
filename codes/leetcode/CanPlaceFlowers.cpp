class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbeds, int n) {
        int vacants = 0;
        int capacity = flowerbeds.size();
        
        if(capacity==1) return (n==0 || flowerbeds[0]==0);
        
        for(int i=0; i<capacity; i++) {
            if(flowerbeds[i]==1) continue;
            
            if(i==0) {
                if(i+1<capacity && flowerbeds[i+1]==0) {
                    flowerbeds[i]=1;
                    vacants++;
                }
            }
            else if(i==capacity-1) {
                if(i-1>=0 && flowerbeds[i-1]==0) {
                    flowerbeds[i]=1;
                    vacants++;
                }
            }
            else {
                if(flowerbeds[i-1]==0 && flowerbeds[i+1]==0) {
                    flowerbeds[i]=1;
                    vacants++;
                }
            }
        }
        
        return (vacants>=n);
    }
};