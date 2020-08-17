/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    var numerator = Math.sqrt(1+(8*n)) - 1;
    var denominator = 2;
    var result = Math.floor(numerator/denominator);
    return result;
};