class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(arr[start]==0) return true;
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int index = q.front();
            q.pop();
            
            if(arr[index]==0) 
                return true;
            else if(!visited[index]) {
                visited[index]=true;
                if(index + arr[index] <= n-1) 
                    q.push(index + arr[index]);
                if(index - arr[index] >= 0) 
                    q.push(index - arr[index]);   
            }
        }
        return false;
    }
};