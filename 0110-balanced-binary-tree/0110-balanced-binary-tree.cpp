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

    int height(TreeNode* root){

        if(root == nullptr)return 0;

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        if(abs(leftheight - rightheight) > 1)return -1;

        if(leftheight == -1 || rightheight == -1)return -1;

        return 1 + max(leftheight,rightheight);

    }

    bool isBalanced(TreeNode* root) {
        
        return height(root)!= -1;

    }
};