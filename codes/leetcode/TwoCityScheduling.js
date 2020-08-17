/**
 * @param {number[][]} costs
 * @return {number}
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
  
  var twoCitySchedCost = function(costs) {
      var costA = []; 
      var costB = [];
      var selected = [];
      var personStatus = []
      var result = 0;
      
      for(var index=0;index<costs.length; index++){ 
          costA.push({"cost": costs[index][0], "person": index});
          costB.push({"cost": costs[index][1], "person": index});
          personStatus.push(false);
      }
  
      costA.sort(compareValues('cost'));
      costB.sort(compareValues('cost'));
          
      var toggle;
      for(var index = 0, indexA=0, indexB=0; index<2*costs.length; index++){
          if(index==0){
              if(costA[indexA].cost < costB[indexB].cost){
                  toggle = "B";
                  personStatus[costA[indexA].person]=true;
                  selected.push(costA[indexA]);
                  costA.splice(indexA, 1);
                  indexA=0;
              } else{
                  toggle = "A";
                  personStatus[costB[indexB].person]=true;
                  selected.push(costB[indexB]);
                  costB.splice(indexB, 1);
                  indexB=0;
              }
          } else if(toggle == "A"){
              if(personStatus[costA[indexA].person]){
                  indexA++;
              } else{
                  toggle = "B";
                  personStatus[costA[indexA].person] = true;
                  selected.push(costA[indexA]);
                  costA.splice(indexA, 1);
                  indexA=0;
              }
          } else if(toggle == "B"){
              if(personStatus[costB[indexB].person]){
                  indexB++;
              } else{
                  toggle = "A";
                  personStatus[costB[indexB].person] = true;
                  selected.push(costB[indexB]);
                  costB.splice(indexB, 1);
                  indexB=0;
              }
          }
      }
      
      selected.forEach(trip=>{
          result+=trip.cost;        
      });
  
      console.log(selected);
      return result;
  };