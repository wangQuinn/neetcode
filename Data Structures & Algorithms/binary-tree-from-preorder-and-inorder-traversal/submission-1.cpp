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

#include <unordered_map> 

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        unordered_map<int,int> lookUpTable; 
        for(int i = 0; i < preorder.size(); i++){
            for(int j = 0; j < inorder.size(); j++){
                if(inorder[j] == preorder[i])
                    lookUpTable.insert({i,j});
            }
        }
        TreeNode* root = buildTreeHelper(preorder, inorder, index, 0, preorder.size() -1 , preorder.size(), lookUpTable);
        return root;
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int> & inorder, int & index, int left, int right, int size, unordered_map<int, int> &lookUpTable){
        
        if(left < 0 || right >= size || index >= size || right < left){
            //cout << "element: NULLPTR index : " << index << " left: " << left << " right: " << right << endl;
            return nullptr; // out of bounds; 
        }
        //cout << "element: " << preorder[index] << " index : " << index << " left: " << left << " right: " << right << " size : " << size << endl;
        TreeNode* root = new TreeNode(preorder[index]);
        //find the index in the inorder tree;
        int index_in = lookUpTable[index];
        //left first then right. 
        index ++; 
        root->left = buildTreeHelper(preorder, inorder, index, left, index_in-1, size, lookUpTable);
        root->right = buildTreeHelper(preorder, inorder, index,  index_in+1, right, size, lookUpTable);
        return root;
    }
};
