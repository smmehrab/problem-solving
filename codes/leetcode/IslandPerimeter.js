/**
 * @param {number[][]} grid
 * @return {number}
 */

function dfsToPerimeter(start, map) {
    let stack = [start]
    let perimeter=0;

    while (stack.length) {
        let activeNode = stack.pop();
        let row = activeNode.row;
        let col = activeNode.col;

        if (row != 0 && map[row - 1][col] == 1) {
            stack.push({ "row": row - 1, "col": col });
        } else {
            perimeter++;
        }

        if (row != map.length - 1 && map[row + 1][col] == 1) {
            stack.push({ "row": row + 1, "col": col });
        } else {
            perimeter++;
        }

        if (col != 0 && map[row][col - 1] == 1) {
            stack.push({ "row": row, "col": col - 1 });
        } else {
            perimeter++;
        }

        if (col != map[0].length - 1 && map[row][col + 1] == 1) {
            stack.push({ "row": row, "col": col + 1 });
        } else {
            perimeter++;
        }
    }

    return perimeter;
}

var islandPerimeter = function (grid) {
    for (let row = 0; row < grid.length; row++) {
        for (let col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == 1) {
                return dfsToPerimeter({ "row": row, "col": col }, grid);
            }
        }
    }
};