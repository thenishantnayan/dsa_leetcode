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

    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(!root)
            return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* bst(vector<int>&ans,int start,int end)
    {
        if(start>end)
        return nullptr;

        int mid = start +(end-start)/2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = bst(ans,start,mid-1);
        root->right = bst(ans,mid+1,end);
            
        return root;
            
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);

        return bst(ans,0,ans.size()-1);         
    }
};