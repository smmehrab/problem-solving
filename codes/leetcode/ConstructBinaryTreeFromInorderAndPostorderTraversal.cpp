class Solution {
public:
    
    TreeNode* helper(unordered_map<int,int>& mp, vector<int>& inorder, vector<int>& postorder, int i_first, int i_last)
    {
        if(i_first > i_last) // base condition by checking size of subtree
            return NULL;
        
        // the approach I have used is to first find the root node value, then break the inorder vector into left subtree and right subtree with respect to the root node. Then filling its left and right subtrees and finally returning the root node.
        int val,index = -1;
        // the node which lies inside the range of given inorder and is rightmost in the postorder is regarded as the current root node.
        for(auto it=postorder.rbegin();it!=postorder.rend();it++)
        {
            if(mp[*it] >= i_first && mp[*it] <= i_last)
            {
                index = mp[*it];
                break;
            }
        }
        
        val = inorder[index];
        TreeNode* root = new TreeNode(val);
        
        root->left = helper(mp,inorder,postorder,i_first,index-1);
        root->right = helper(mp,inorder,postorder,index+1,i_last);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int> mp;
        
        int n = inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]] = i;
        
        
        TreeNode* actualroot = helper(mp,inorder,postorder,0,n-1);
        
        return actualroot;
        
    }
};