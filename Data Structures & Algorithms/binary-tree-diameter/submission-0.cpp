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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxPath = 0;
        int height = getHeight(root, maxPath);
        return maxPath;
        
    }
    int getHeight(TreeNode* root, int& maxPath){
        if(nullptr == root) return 0;
        int leftHeight = 1 + getHeight(root->left, maxPath);
        int rightHeight = 1 + getHeight(root->right, maxPath);
        maxPath = max(maxPath, leftHeight + rightHeight - 2); //if this is the  node. 
        return max(leftHeight, rightHeight);
    }
};
