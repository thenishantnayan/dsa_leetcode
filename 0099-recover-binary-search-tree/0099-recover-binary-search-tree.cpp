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
        
        //LNR
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void filledbst(TreeNode* root,vector<int>&ans,int &index)
    {
        if(!root)
            return;
            
        //inorder
        filledbst(root->left,ans,index);
        //replace current value with correct value 
        root->val = ans[index];
        index++;
        filledbst(root->right,ans,index);
    }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
        
        int index=0;
        filledbst(root,ans,index);
    }
};