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
 int n1,n2;
class Solution {
public:

    void find(TreeNode* root,int &ans)
    {
        if(!root)
            return;
        
        if(root->val > n1 && root->val > n2)
            find(root->left,ans);
        else if(root->val < n1 && root->val < n2)
            find(root->right,ans);
        else
        {
            //LNR
            find(root->left,ans);
            ans += root->val;
            find(root->right,ans);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans =0;
        n1 = low,n2 = high;
        find(root,ans);
        return ans;
    }
};