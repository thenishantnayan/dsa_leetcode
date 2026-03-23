class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> q;           // queue used for BFS (level order)
        q.push(root);                 // push root into queue (will handle NULL below)

        vector<vector<int>> ans;      // final 2D answer

        if (root == NULL) return ans; // IMPORTANT: if tree empty, return {}

        TreeNode * temp;

        while (!q.empty())            // BFS loop till queue becomes empty
        {
            int sz = q.size();        // number of nodes in current level
            vector<int> level;        // will store values of this entire level

            while (sz--)              // process exactly sz nodes (one full level)
            {
                temp = q.front();     // get current node
                q.pop();              // remove it from queue

                level.push_back(temp->val);   // store its value in current level

                // if left child exists, push to queue for next level
                if (temp->left)
                    q.push(temp->left);

                // if right child exists, push to queue for next level
                if (temp->right)
                    q.push(temp->right);
            }

            ans.push_back(level);      // store the completed level in result
        }

        return ans;                    // return all levels
    }
};