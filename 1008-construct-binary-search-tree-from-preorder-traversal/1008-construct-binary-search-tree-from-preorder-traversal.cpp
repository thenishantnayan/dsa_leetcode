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

    /*
        This function constructs the BST using preorder traversal.
        
        preorder -> given preorder array
        index    -> current index in preorder (passed by reference so it updates globally)
        lower    -> lower bound for valid BST values
        upper    -> upper bound for valid BST values
    */
    TreeNode* bst(vector<int>& preorder, int &index, int lower, int upper)
    {
        // Base case 1:
        // If all elements are used, stop recursion
        if (index == preorder.size())
            return nullptr;

        // Base case 2:
        // If current value does not lie within valid BST range,
        // it cannot be part of this subtree
        if (preorder[index] < lower || preorder[index] > upper)
            return nullptr;

        // Create the root node using current preorder value
        TreeNode* root = new TreeNode(preorder[index]);

        // Move to next element in preorder
        index++;

        // All values for left subtree must be:
        // lower < value < root->val
        root->left = bst(preorder, index, lower, root->val);

        // All values for right subtree must be:
        // root->val < value < upper
        root->right = bst(preorder, index, root->val, upper);

        // Return constructed subtree
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bst(preorder, index, INT_MIN, INT_MAX);
    }
};
