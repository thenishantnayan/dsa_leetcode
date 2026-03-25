/**
 * Definition for a binary tree node.
 */
class Solution {
public:

    // Find position of target in inorder traversal
    int find(vector<int> in, int target, int start, int end)
    {
        for(int i = start; i <= end; i++)
        {
            if(in[i] == target)
                return i;
        }
        return -1;
    }

    // Build tree using inorder and postorder
    TreeNode* Tree(vector<int> in, vector<int> post,
                   int inStart, int inEnd, int index)
    {
        // Base case
        if(inStart > inEnd)
            return nullptr;

        // Last element of postorder is the root
        TreeNode* root = new TreeNode(post[index]);

        // Find root position in inorder
        int pos = find(in, post[index], inStart, inEnd);

        // IMPORTANT:
        // Postorder = Left → Right → Root
        // So we build RIGHT subtree first

        // Build right subtree
        root->right = Tree(in, post,
                           pos + 1, inEnd,
                           index - 1);

        // Build left subtree
        // Skip nodes of right subtree in postorder
        root->left = Tree(in, post,
                          inStart, pos - 1,
                          index - (inEnd - pos) - 1);

        return root;
    }

    // Driver function
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        // Start from last index of postorder
        return Tree(inorder, postorder, 0, n - 1, n - 1);
    }
};