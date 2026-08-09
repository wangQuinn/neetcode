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
    int maxPathSum(TreeNode* root) {
        int maxSum =root->val;
        int topPath = helper(root, maxSum);
        return maxSum;
    }
    int helper(TreeNode* root, int& maxSum){
        if(nullptr == root) return 0;
        // 2 options -> it's the splitting node (BOTH LEFT AND RIGHT) or it's not (LEFT OR RIGHT)
        int right = helper(root->right, maxSum);
        int left = helper(root->left, maxSum);
        int asSplittingNode = right + left + root->val;
        cout << "asSplittingNode: " << asSplittingNode << endl;
        maxSum = max(maxSum, asSplittingNode); //0 for the negatives. 
        return max(root->val + max(right, left), 0);
    }

};
