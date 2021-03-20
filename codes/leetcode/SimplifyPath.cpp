class Solution {
private:
    vector<string> split(string s, string separator) {
        vector<string> splits;
        int start = 0, end = s.find(separator);
        while (end != -1) {
            splits.push_back(s.substr(start, end- start));
            start = end + separator.size();
            end = s.find(separator, start);
        }
        splits.push_back(s.substr(start, end-start));
        return splits;
    }
    
public:
    string simplifyPath(string path) {
        vector<string> dirs = split(path, "/");
        
        vector<string> simplified;
        for(string dir : dirs) {
            if(dir == "." || dir.size()==0)
                continue;
            else if(dir == "..") {
                if(!simplified.empty())
                    simplified.pop_back();
            }
            else
                simplified.push_back(dir);
        }
        
        path = "/";
        for(string dir : simplified) {
            if(dir.back()!='/')
                dir += "/";
            path += dir;
        }
        
        if (!path.empty() && path.size()>1) 
            path.pop_back();
    
        return path;
    }
};