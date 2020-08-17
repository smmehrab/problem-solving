/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    var z = x^y;
    var result=0;
    while (z){
        z = z & (z-1);
        result++;
    }
    return result;
};