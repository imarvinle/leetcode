//
// Created by marvinle on 2018/10/23 下午10:46.
//

// 题号: 110

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        if(root == NULL)
            return true;

        if(!isBalanced(root->left))
            return false;
        if(!isBalanced(root->right))
            return false;
        if(abs(getHight(root->left)-getHight(root->right)) >= 2)
            return false;

        return true;
    }

private:
    int getHight(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = getHight(root->left);
        int right = getHight(root->right);
        return max(left,right)+1;
    }
};

