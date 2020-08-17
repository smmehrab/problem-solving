/**
 * @param {number} n
 * @param {number[]} left
 * @param {number[]} right
 * @return {number}
 */
var getLastMoment = function (n, left, right) {
    var leftMax = Math.max(...left);
    var rightMin = Math.min(...right);
    return Math.max(leftMax, n-rightMin);
};