//
// Created by marvinle on 2018/10/23.
//


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        if(root == NULL)
//            return true;
//        if(root->left)
//        {
//            if(!(root->left->val < root->val && getMax(root->left) < root->val))
//                return false;
//            if(!isValidBST(root->left))
//                return false;
//        }
//        if(root->right)
//        {
//            if(!(root->right->val < root->val && getMin(root->right) > root->val))
//                return false;
//            if(!isValidBST(root->right))
//                return false;
//        }
//        return true;
//    }
//private:
//    int getMin(TreeNode* root)
//    {
//        if(root == NULL)
//            return INT_MAX;
//        if(root->left == NULL && root->right == NULL)
//            return root->val;
//        int left = getMin(root->left);
//        int right = getMin(root->right);
//        return min(min(root->val,right), left);
//    }
//    int getMax(TreeNode* root)
//    {
//        if(root == NULL)
//            return INT_MIN;
//        if(root->left == NULL && root->right == NULL)
//            return root->val;
//        int left = getMax(root->left);
//        int right = getMax(root->right);
//        return max(max(root->val,right), left);
//    }
//};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;

        return helper(root, numeric_limits<long int>::min(), numeric_limits<long int >::max());
    }
    // 分别递归的判断，左右子树，同时将左右子树的边界范围传下去
    bool helper(TreeNode* root, long int min, long int max) {
        if(root == nullptr)
            return true;
        if(root->val <= min) return false;
        if(root->val >= max) return false;
        return helper(root->left, min, root->val) &&
               helper(root->right, root->val,max);
    }
};