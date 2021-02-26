class Solution {
public:
    int minAddToMakeValid(string s) {
        int add = 0;
        stack<char> p;
        for(char c : s) {
            if(c=='(')  p.push(c);
            else if(p.empty()) ++add;
            else p.pop();
        }
        add += p.size();
        return add;
    }
};