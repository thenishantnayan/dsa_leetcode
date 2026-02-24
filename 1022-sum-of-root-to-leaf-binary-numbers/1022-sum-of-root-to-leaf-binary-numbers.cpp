/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root,int current)
    {
        if(!root)
        return 0;

        //build binary number 
        //new_number = old_number * 2 + new_bit
        //current = (current << 1) | root->val;

        current = (current<<1) | root->val;

        //leaf node
        if(root->left ==nullptr && root->right == nullptr)
        return current;

        return dfs(root->left,current)+dfs(root->right,current);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};