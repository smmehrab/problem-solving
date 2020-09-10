class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0, b=0, n=secret.size();
        int contains[10];
        memset(contains, 0, sizeof(contains));
        for(char c : secret) contains[c-'0']++;

        for(int i=0; i<n; i++){
            if(guess[i]==secret[i]) {
                a++;
                contains[guess[i]-'0']--;
                guess[i] = '.';
            }
        }
        
        for(int i=0; i<n; i++){
            if(guess[i]!='.'){
                if(contains[guess[i]-'0']!=0){
                    b++;
                    contains[guess[i]-'0']--;
                }   
            }
        }
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};