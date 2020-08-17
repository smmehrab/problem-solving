/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    var stack = [];
    var queue = [];
    var number = [];
    
    if(root){
        queue.unshift({"node":root, "level":0});
        while(queue.length>0){
            var active = queue.shift();
            
            if(active.node.left){
                queue.push({"node":active.node.left, "level":active.level+1});
            } 

            if(active.node.right){
                queue.push({"node":active.node.right, "level":active.level+1});
            }

            stack.push({"val": active.node.val, "level": active.level});
        }


        while(stack.length>0){
            var activeNode = stack.pop();
            console.log(activeNode);
            if(!number[activeNode.level]){
                number[activeNode.level]=[];
            }
            number[activeNode.level].unshift(activeNode.val);
        } 
    }
    
    number.reverse();
    // console.log(number); 
    return number;
};