/**
 * @param {number} n
 * @return {number}
 */

var nthUglyNumber = function (n) {
    var nextMultipleOf2 = 2;
    var nextMultipleOf3 = 3;
    var nextMultipleOf5 = 5;
    var previousUglyMultipleOf2 = 0;
    var previousUglyMultipleOf3 = 0;
    var previousUglyMultipleOf5 = 0;
    var uglyNumbers = [];

    uglyNumbers[0] = 1;

    for (var i = 1; i < n; i++) {
        uglyNumbers[i] = Math.min(nextMultipleOf2, nextMultipleOf3, nextMultipleOf5);
        if (uglyNumbers[i] == nextMultipleOf2) {
            previousUglyMultipleOf2++;
            nextMultipleOf2 = uglyNumbers[previousUglyMultipleOf2] * 2;
        }
        if (uglyNumbers[i] == nextMultipleOf3) {
            previousUglyMultipleOf3++;
            nextMultipleOf3 = uglyNumbers[previousUglyMultipleOf3] * 3;
        }
        if (uglyNumbers[i] == nextMultipleOf5) {
            previousUglyMultipleOf5++;
            nextMultipleOf5 = uglyNumbers[previousUglyMultipleOf5] * 5;
        }
    }
    return uglyNumbers[n - 1];
};