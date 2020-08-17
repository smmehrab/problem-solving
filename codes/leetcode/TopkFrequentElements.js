/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */

function compareValues(key, order = 'asc') {
  return function innerSort(a, b) {
    if (!a.hasOwnProperty(key) || !b.hasOwnProperty(key)) {
      // property doesn't exist on either object
      return 0;
    }

    const varA = (typeof a[key] === 'string')
      ? a[key].toUpperCase() : a[key];
    const varB = (typeof b[key] === 'string')
      ? b[key].toUpperCase() : b[key];

    let comparison = 0;
    if (varA > varB) {
      comparison = 1;
    } else if (varA < varB) {
      comparison = -1;
    }
    return (
      (order === 'desc') ? (comparison * -1) : comparison
    );
  };
}

var topKFrequent = function(nums, k) {
    var modifiedNums = [];
    var result=[];
    var minNumber = 99999;
    
    for(var index=0; index<nums.length; index++){
        var number = nums[index];
        if(number<minNumber){
            minNumber = number;
        }
    }
    
    if(minNumber>=0){
        minNumber = 0;
    } else{
        minNumber *= -1;
    }
    
    for(var index=0; index<nums.length; index++){
        var number = nums[index];
        modifiedNums[number+minNumber]={"number":number, "frequency": 0};
    }
    
    for(var index=0; index<nums.length; index++){
        var number = nums[index];
        modifiedNums[number+minNumber].frequency++;
    }
    
    modifiedNums.sort(compareValues("frequency", "desc"));
    
    for(var index=0; index<k; index++){
        result.push(modifiedNums[index].number);
    }
    
    return result;
};