class Solution {
private:
    int sum, tilt;
    int findSum(TreeNode* root) {
      if(!root) return 0;
      int leftSum = findSum(root->left);
      int rightSum = findSum(root->right);
      tilt += abs(leftSum-rightSum);
      return (leftSum+(root->val)+rightSum);
    }
    
public:
    int findTilt(TreeNode* root) {
        tilt = 0;
        sum = findSum(root);
        return tilt;
    }
};