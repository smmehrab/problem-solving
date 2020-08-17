/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canMakeArithmeticProgression = function(arr) {
    
    arr.sort(function(a,b){return a - b});
    var progression = arr[1]-arr[0];
    for(var index=1;index<arr.length;index++){
        if(arr[index]-arr[index-1] != progression){
            return false;
        }
    }
    
    return true;
};