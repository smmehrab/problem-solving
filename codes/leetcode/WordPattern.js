/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, input) {
    var words = input.split(" ");
    if(words.length!=pattern.length) 
        return false;
    
    var patternToWords = new Map(); 
    var wordsToPattern = new Map(); 
    for(var i=0; i<words.length; i++){
        mappedWord = patternToWords.get(pattern[i])
        mappedPattern = wordsToPattern.get(words[i])

        if(mappedWord && mappedWord!=words[i]){
            return false;
        }
        else if(mappedPattern && mappedPattern!=pattern[i]){
            return false;
        }        
        else if(!mappedWord && !mappedPattern){
            patternToWords.set(pattern[i], words[i]);
            wordsToPattern.set(words[i], pattern[i]);
        }
    }

    return true;
};