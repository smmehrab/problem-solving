/**
 * @param {number} hour
 * @param {number} minutes
 * @return {number}
 */
var angleClock = function(hour, minutes) {
    var answer = Math.abs((minutes-(((hour%12)*5)+(minutes/12.00)))*6.00);
    if(answer>180){
        answer=360-answer;
    }
    return answer;
};