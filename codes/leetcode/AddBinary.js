/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
    var result = "";
    var sum = 0;
    var carry = 0;

    var aIndex = a.length - 1;
    var bIndex = b.length - 1;

    while (aIndex >= 0 || bIndex >= 0) {
        var aDigit = 0, bDigit = 0;

        if(aIndex>=0){
            aDigit = parseInt(a[aIndex]);
        }

        if(bIndex>=0){
            bDigit = parseInt(b[bIndex]);
        }

        sum = (aDigit + bDigit + carry)%2;
        carry = Math.floor((aDigit + bDigit + carry)/2);

        result = sum + result;

        aIndex--;
        bIndex--;
    }

    if(carry){
        result = carry + result;
    }

    return result;
};