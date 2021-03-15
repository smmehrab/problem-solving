class Entry {
public:
    string longURL;
    string shortURL;
    Entry(string longURL, string shortURL) {
        this->longURL = longURL;
        this->shortURL = shortURL;
    }
};

class Solution {
private:
    const string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    unsigned long long ID = 1;
    unordered_map<unsigned long long, Entry*> DATABASE;
    
    string idToShortURL(unsigned long long id) {  
        string shortURL;  
        while (id) {
            shortURL.push_back(alphabets[id%62]);
            id /= 62;
        }  
        reverse(shortURL.begin(), shortURL.end());
        shortURL = "http://tinyurl.com/" + shortURL;
        return shortURL;
    }
    
    unsigned long long shortURLtoId(string shortURL) {
        unsigned long long id = 0;
        for (char c : shortURL) {
            id *= 62;
            if ('a'<=c && c<='z')
              id = (c-'a');
            else if ('A'<=c && c<='Z')
              id = 26 + (c-'A');
            else if ('0'<=c && c<='9')
              id = 52 + (c-'0');
        }
        return id;
    }
    
public:
    // Encodes a URL to a shortened URL.
    string encode(string longURL) {
        string shortURL = idToShortURL(ID);
        Entry* entry = new Entry(longURL, shortURL);
        DATABASE.insert({ID++, entry});
        return shortURL;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortURL) {
        unsigned long long id = shortURLtoId(shortURL);
        return (DATABASE.find(id) != DATABASE.end()) ? DATABASE[id]->longURL : "Error 404"; 
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));