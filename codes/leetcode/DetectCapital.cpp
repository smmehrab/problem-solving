class Solution {
public:
    bool detectCapitalUse(string word) {
        int index = 0;
        int letterCount = word.size();
        int firstLetter = word[0] - 65;
        char letter;

        for(index=1;index<letterCount;index++){
            letter = word[index];
            if(letter > 96 && firstLetter < 26)
                break;
            else if(letter < 91 && firstLetter > 26)
                break;
        }
        
        if(index == letterCount)
            return true;
        else if(firstLetter > 26)
            return false;
        
        for(index=1; index<letterCount; index++){
            letter = word[index];
            if(letter < 91)
                break;
        }
        
        if(index == letterCount)
            return true;
        
        return false; 
    }
};