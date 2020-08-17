/**
 * @param {number[]} cells
 * @param {number} N
 * @return {number[]}
 */
var prisonAfterNDays = function(cells, N) {
    
    var toOccupy;
    toOccupy = cells[0];
    for(var index=0; index<8; index++){
        if(index>=2){
            if(cells[index]==toOccupy){
                toOccupy = cells[index-1];
                cells[index-1]=1;
            } else if(cells[index]!=toOccupy){
                toOccupy = cells[index-1];
                cells[index-1]=0;
            }
        }
            
        if(index==0||index==7){
            cells[index]=0;
        }
    }
    
    N--;
    N=(N%14);
    
    for(var day=0; day<N; day++){
        toOccupy = cells[0];
        for(var index=0; index<8; index++){
            if(index>=2){
                if(cells[index]==toOccupy){
                    toOccupy = cells[index-1];
                    cells[index-1]=1;
                } else if(cells[index]!=toOccupy){
                    toOccupy = cells[index-1];
                    cells[index-1]=0;
                }
            }
            
            if(index==0||index==7){
                cells[index]=0;
            }
        }
    }
    
    return cells;
};