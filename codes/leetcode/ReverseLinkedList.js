/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    var previous = null;
    var current = head;
    var following = head;
      
    while(current) {
      following = following.next;
      current.next = previous;
      previous = current;    
      current = following;
    }
      
    return previous;
  };