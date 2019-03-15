//
// Created by marvinle on 2019/3/14 1:46 PM.
//


// leetcode 236

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
    // 分别递归查询左右子树查找p q，只要存在任何一个就返回，
    // 那么如果q p 分别出现在root左右子树。那么最近公共祖先就root
    // 如果只有某一变返回不为null的话，公共祖先就是他自己
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root  == p || root  ==  q)
            return  root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right  = lowestCommonAncestor(root->right, p, q);
        // 都不为nullptr，则root是
        if(left && right)
            return root;
        if(left)
            return left;
        if(right)
            return right;
        return nullptr;
    }
};