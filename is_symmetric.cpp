//
// Created by marvinle on 2018/10/23.
//

// 题号: 101
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    /* 递归解法
public:

    // 思路 左右子树的中序遍历互为逆序
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        if(left != NULL && right != NULL)
        {
            if(left->val != right->val)
                return false;
            if(!isSymmetric(left->left,right->right))
                return false;
            if(!isSymmetric(left->right, right->left))
                return false;
        }
        return false;

    }
     */

    // 迭代解法， 二叉树的中序遍历， 右边子树采用右子树先遍历的方式

public:
    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
            return true;
        stack<TreeNode*> ls, rs;
        TreeNode *left, *right;
        left = root->left;
        right = root->right;

        while((left && right) || (!ls.empty() && !rs.empty()))
        {
            if(left && right)
            {
                ls.push(left);
                rs.push(right);
                left = left->left;
                right = right->right;
            } else if((right==NULL && left!=NULL) || (right!=NULL && left==NULL))
            {
                return false;
            } else {
                left = ls.top();
                right = rs.top();
                ls.pop();
                rs.pop();
                if(left->val != right->val)
                    return false;
                left = left->right;
                right = right->left;
            }
        }
        if(!ls.empty() || !rs.empty())
            return false;
        if(left || right)
            return false;
        return true;
    }
};

