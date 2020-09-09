/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    version1 = version1.split(".");
    version2 = version2.split(".");
    var len1 = version1.length;
    var len2 = version2.length;
    
    if(len1>len2){
        for(var i=0; i<(len1-len2); i++){
            version2.push("0");
        }
    }
    else if(len2>len1){
        for(var i=0; i<(len2-len1); i++){
            version1.push("0");
        }
    }
    
    len1 = version1.length;
    len2 = version2.length;
    for(var i=0; i<len1; i++){
        if(parseInt(version1[i]) == parseInt(version2[i]))
            continue;
        else if(parseInt(version1[i]) > parseInt(version2[i]))
            return 1;
        else 
            return -1;
    }
    
    
    return 0;
};